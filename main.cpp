#pragma region INCLUDES
#include <Arduino.h>
#include <ArduinoOTA.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#include "modbusRTU.h"
#include "util.h"
#include <time.h>
#include "SDM72DM.h"
#include "ws100-19l3.h"
#pragma endregion

#pragma region DEFINES
#define MODBUSRTU_SPEED 9600            // bps for the modbusRTU, default 9600, 8N1 on the SDM72D-M
#define RS485_DIRECTION 2               // direction pin for the RS485 controller ( DE and !RE pins tied together)
#define MODBUSRTU_READ_INTERVAL 10000 // 30000   // read data every 30 seconds
#define MODBUSRTU_SLAVE_1 1             // ID of the first slave

#define QUEUESIZE 1
#pragma endregion

#pragma region GLOBAL VARS
String gDeviceName = String() + "powermeter-" + ESP.getChipId();
String gTopic = String() + "wifi2mqtt/powermeter/" + ESP.getChipId();
char lastResult[30];
char timeDate[40];
unsigned long lastRead1Successfull;
String R = "";
String RR = "";
#pragma endregion

#pragma region GLOBAL OBJECTS
WiFiManager wifiManager;
WiFiClient wifiClient;
ESP8266WebServer webServer(80);
ModBusRTU modbus;
#pragma endregion


void setupWiFi(){
    wifi_set_sleep_type(NONE_SLEEP_T); // prevent wifi sleep (stronger connection)

    // On Access Point started (not called if wifi is configured)
    wifiManager.setAPCallback([](WiFiManager *mgr)
                              {
                                Serial.println(String("Please connect to Wi-Fi"));
                                Serial.println(String("Network: ") + mgr->getConfigPortalSSID());
                                Serial.println(String("Password: 12341234"));
                                Serial.println(String("Then go to ip: 10.0.1.1")); 
                              }
    );

    wifiManager.setAPStaticIPConfig(IPAddress(10, 211, 1, 1), IPAddress(10, 211, 1, 1), IPAddress(255, 255, 255, 0));
    wifiManager.setConfigPortalTimeout(60);
    wifiManager.autoConnect(gDeviceName.c_str(), "12341234"); // IMPORTANT! Blocks execution. Waits until connected

    // Restart if not connected
    if (WiFi.status() != WL_CONNECTED)
    {
        ESP.restart();
    }

    String hostname = String() + "esp-" + gDeviceName;
    hostname.replace('.', '_');
    WiFi.hostname(hostname);
}

void setupWebServer(){
    webServer.begin();

    String domainLan = String() + WiFi.hostname() + ".lan";

    String menu;
    menu += "<div>";
    menu += String() + "<a href='http://" + domainLan + "'>" + domainLan + "</a> | ";
    menu += "<a href='/'>index</a> ";
    menu += "<a href='/restart'>restart</a> ";
    menu += "<a href='/logout'>logout</a> ";
    menu += "</div><hr>";

    webServer.on("/", [menu](){
        String str = ""; 
        str += menu;
        str += "<pre>";
        str += String() + "           Uptime: " + (millis() / 1000) + " \n";
        str += String() + "      FullVersion: " + ESP.getFullVersion() + " \n";
        str += String() + "      ESP Chip ID: " + ESP.getChipId() + " \n";
        str += String() + "         Hostname: " + WiFi.hostname() + " \n";
        str += String() + "       CpuFreqMHz: " + ESP.getCpuFreqMHz() + " \n";
        str += String() + "      WiFi status: " + wifiClient.status() + " \n";
        str += String() + "         FreeHeap: " + ESP.getFreeHeap() + " \n";
        str += String() + "       SketchSize: " + ESP.getSketchSize() + " \n";
        str += String() + "  FreeSketchSpace: " + ESP.getFreeSketchSpace() + " \n";
        str += String() + "    FlashChipSize: " + ESP.getFlashChipSize() + " \n";
        str += String() + "FlashChipRealSize: " + ESP.getFlashChipRealSize() + " \n";
        str += String() + " Last read result: " + lastResult + "\n";
        str += String() + "             Date: " + timeDate + "\n\n\n\n";
        str += String() + RR;
        str += "</pre>";
        webServer.send(200, "text/html; charset=utf-8", str); 
    });

    // Restart ESP
    webServer.on("/restart", [menu](){
        if(webServer.method() == HTTP_POST){
            webServer.send(200, "text/html", "OK");
            ESP.reset();
        }else{
            String output = "";
            output += menu;
            output += String() + "<pre>";
            output += String() + "Uptime: " + (millis() / 1000) + " \n";
            output += String() + "</pre>";
            output += "<form method='post'><button>Restart ESP now!</button></form>";
            webServer.send(200, "text/html", output);
        } 
    });

    // Logout (reset wifi settings)
    webServer.on("/logout", [menu](){
        if(webServer.method() == HTTP_POST){
            webServer.send(200, "text/html", "OK");
            wifiManager.resetSettings();
            ESP.reset();
        }else{
            String output = "";
            output += menu;
            output += String() + "<pre>";
            output += String() + "Wifi network: " + WiFi.SSID() + " \n";
            output += String() + "        RSSI: " + WiFi.RSSI() + " \n";
            output += String() + "    hostname: " + WiFi.hostname() + " \n";
            output += String() + "</pre>";
            output += "<form method='post'><button>Forget</button></form>";
            webServer.send(200, "text/html", output);
        } 
    });

}

void setupModbusRTU(){
    Serial.begin(MODBUSRTU_SPEED); // 74880 ESP8266 native, 9600 - power meter ModbusRTU default
    pinMode(RS485_DIRECTION, OUTPUT);
    digitalWrite(RS485_DIRECTION, 0); // Init in receive mode
    modbus.begin(1, Serial); // Modbus slave ID 1

    modbus.preTransmission([](){
        digitalWrite(RS485_DIRECTION, 1);
    });

    modbus.postTransmission([](){
        digitalWrite(RS485_DIRECTION, 0);
    });
    lastRead1Successfull = 0;
}

void setup(){
    setupModbusRTU();
    setupWiFi();
    ArduinoOTA.begin(); // firmware updates via WiFi
    setupWebServer();
    configTime(1 * 3600, 3600, "pool.ntp.org", "time.nist.gov");
}

void timeLoop(){
    static unsigned long stLastTimeUpdate = 0;
    if (stLastTimeUpdate && millis() - stLastTimeUpdate < 10000) return; // update every 10 seconds
    stLastTimeUpdate = millis();

    //printLocalTime(&Serial);    // send to serial
    printLocalTime(timeDate, 40); // update global variable timeDate that is displayed on root web page

}

uint8_t readMeter(u_int8_t slave_id){
    uint8_t result;
    char x[45];
    char lastResult[30];
    
    R = "";

    //modbus.setSlaveID(slave_id);

    result = modbus.readInputRegisters(WS100_MODBUS_OFFSET_VOLTAGE, 2);
    modbus.snprintResult(lastResult, 30, result);
    if (result == modbus.ku8MBSuccess){
        snprintf(x, 45, "V: %.3f\n", ((modbus.getResponseBuffer(0) << 16 ) + modbus.getResponseBuffer(1)) / WS100_MODBUS_PRECISION_VOLTAGE);
        R = R + x; 
    } else {
        R = R + "V: " + lastResult + "\n";
    }
    R+="\n";
    delay(1);

    result = modbus.readInputRegisters(WS100_MODBUS_OFFSET_CURRENT, 2);
    modbus.snprintResult(lastResult, 30, result);
    if (result == modbus.ku8MBSuccess){
        snprintf(x, 45, "A: %.3f\n", ((modbus.getResponseBuffer(0) << 16 ) + modbus.getResponseBuffer(1)) / WS100_MODBUS_PRECISION_CURRENT);
        R = R + x; 
    } else {
        R = R + "A: " + lastResult + "\n";
    }
    R+="\n";
    delay(1);

    result = modbus.readInputRegisters(WS100_MODBUS_OFFSET_ACTIVEPOWER, 2);
    modbus.snprintResult(lastResult, 30, result);
    if (result == modbus.ku8MBSuccess){
        snprintf(x, 45, "W: %d\n", ((modbus.getResponseBuffer(0) << 16 ) + modbus.getResponseBuffer(1)) / WS100_MODBUS_PRECISION_ACTIVEPOWER);
        R = R + x; 
    } else {
        R = R + "W: " + lastResult + "\n";
    }
    R+="\n";
    delay(1);


    result = modbus.readInputRegisters(WS100_MODBUS_OFFSET_APPARENTPOWER, 2);
    modbus.snprintResult(lastResult, 30, result);
    if (result == modbus.ku8MBSuccess){
        snprintf(x, 45, "VA: %d\n", ((modbus.getResponseBuffer(0) << 16 ) + modbus.getResponseBuffer(1)) / WS100_MODBUS_PRECISION_APPARENTPOWER);
        R = R + x; 
    } else {
        R = R + "VA: " + lastResult + "\n";
    }
    R+="\n";
    delay(1);

    
    result = modbus.readInputRegisters(WS100_MODBUS_OFFSET_FREQUENCY, 1);
    modbus.snprintResult(lastResult, 30, result);
    if (result == modbus.ku8MBSuccess){
        snprintf(x, 45, "Hz: %.1f\n", modbus.getResponseBuffer(0) / WS100_MODBUS_PRECISION_FREQUENCY);
        R = R + x; 
    } else {
        R = R + "Hz: " + lastResult + "\n";
    }
    R+="\n";
    delay(1);


    RR = String() + timeDate + "\n" + R;

    return result;
}

void readMeterLoop(){
    readMeter(MODBUSRTU_SLAVE_1);
}


void loop()
{
    ArduinoOTA.handle();
    webServer.handleClient();
    timeLoop();
    readMeterLoop();
}