#ifndef _WS100_19L3_H_
#define _WS100_19L3_H_

// https://stromzähler.eu/media/pdf/d6/91/23/WS100-19xx_DE.pdf

// 1.Instantaneous parameters
#define WS100_MODBUS_OFFSET_VOLTAGE 0x0100             // V 3+3
#define WS100_MODBUS_PRECISION_VOLTAGE 1000.00

#define WS100_MODBUS_OFFSET_CURRENT 0x0102             // A 2+3
#define WS100_MODBUS_PRECISION_CURRENT 1000.00

#define WS100_MODBUS_OFFSET_ACTIVEPOWER 0x0104         // W 5+0
#define WS100_MODBUS_PRECISION_ACTIVEPOWER 1

#define WS100_MODBUS_OFFSET_APPARENTPOWER 0x0106       // VA 5+0
#define WS100_MODBUS_PRECISION_APPARENTPOWER 1

#define WS100_MODBUS_OFFSET_REACTIVEPOWER 0x0108       // VAr 5+0
#define WS100_MODBUS_PRECISION_REACTIVEPOWER 1

#define WS100_MODBUS_OFFSET_FREQUENCY 0x010A           // Hz 2+1  // ONE BYTE
#define WS100_MODBUS_PRECISION_FREQUENCY 10.00

#define WS100_MODBUS_OFFSET_POWERFACTOR 0x010B         // PF 1+3  // ONE BYTE With CL indication, active power with sign of forward and reverse(modbus)
#define WS100_MODBUS_PRECISION_POWERFACTOR 1000.00


// 2.Energy parameters
#define WS100_MODBUS_OFFSET_TOTALFWACTIVEENERGY 0x010E      // kWh 6+2
#define WS100_MODBUS_PRECISION_TOTALFWACTIVEENERGY 100.00

#define WS100_MODBUS_OFFSET_TOTALFWACTIVEENERGYT1 0x0110    // kWh 6+2 // without tariffs version: T1= Total forward active energy
#define WS100_MODBUS_PRECISION_TOTALFWACTIVEENERGYT1 100.00

#define WS100_MODBUS_OFFSET_TOTALFWACTIVEENERGYT2 0x0112    // kWh 6+2
#define WS100_MODBUS_PRECISION_TOTALFWACTIVEENERGYT2 100.00

#define WS100_MODBUS_OFFSET_TOTALFWACTIVEENERGYT3 0x0114    // kWh 6+2
#define WS100_MODBUS_PRECISION_TOTALFWACTIVEENERGYT3 100.00

#define WS100_MODBUS_OFFSET_TOTALFWACTIVEENERGYT4 0x0116    // kWh 6+2
#define WS100_MODBUS_PRECISION_TOTALFWACTIVEENERGYT4 100.00


#define WS100_MODBUS_OFFSET_TOTALRWACTIVEENERGY 0x0118      // kWh 6+2 
#define WS100_MODBUS_PRECISION_TOTALRWACTIVEENERGY 100.00

#define WS100_MODBUS_OFFSET_TOTALRWACTIVEENERGYT1 0x011A    // kWh 6+2 // without tariffs version: T1=Total reverse active energy
#define WS100_MODBUS_PRECISION_TOTALRWACTIVEENERGYT1 100.00

#define WS100_MODBUS_OFFSET_TOTALRWACTIVEENERGYT2 0x011C    // kWh 6+2
#define WS100_MODBUS_PRECISION_TOTALRWACTIVEENERGYT2 100.00

#define WS100_MODBUS_OFFSET_TOTALRWACTIVEENERGYT3 0x011E    // kWh 6+2
#define WS100_MODBUS_PRECISION_TOTALRWACTIVEENERGYT3 100.00

#define WS100_MODBUS_OFFSET_TOTALRWACTIVEENERGYT4 0x0120    // kWh 6+2
#define WS100_MODBUS_PRECISION_TOTALRWACTIVEENERGYT4 100.00


#define WS100_MODBUS_OFFSET_TOTALACTIVEENERGY 0x0122      // kWh 6+2 
#define WS100_MODBUS_PRECISION_TOTALACTIVEENERGY 100.00

#define WS100_MODBUS_OFFSET_TOTALACTIVEENERGYT1 0x0124    // kWh 6+2 // without tariffs version: T1=Total active energy
#define WS100_MODBUS_PRECISION_TOTALACTIVEENERGYT1 100.00

#define WS100_MODBUS_OFFSET_TOTALACTIVEENERGYT2 0x0126    // kWh 6+2
#define WS100_MODBUS_PRECISION_TOTALACTIVEENERGYT2 100.00

#define WS100_MODBUS_OFFSET_TOTALACTIVEENERGYT3 0x0128    // kWh 6+2
#define WS100_MODBUS_PRECISION_TOTALACTIVEENERGYT3 100.00

#define WS100_MODBUS_OFFSET_TOTALACTIVEENERGYT4 0x012A    // kWh 6+2
#define WS100_MODBUS_PRECISION_TOTALACTIVEENERGYT4 100.00


#define WS100_MODBUS_OFFSET_TOTALFWRECTIVEENERGY 0x012C      // kWharh 6+2 
#define WS100_MODBUS_PRECISION_TOTALFWRECTIVEENERGY 100.00

#define WS100_MODBUS_OFFSET_TOTALFWREACTIVEENERGYT1 0x012E    // kWharh 6+2 // without tariffs version: T1=Total forward reactive energy
#define WS100_MODBUS_PRECISION_TOTALFWRECTIVEENERGYT1 100.00

#define WS100_MODBUS_OFFSET_TOTALFWRECTIVEENERGYT2 0x0130   // kWharh 6+2
#define WS100_MODBUS_PRECISION_TOTALFWRECTIVEENERGYT2 100.00

#define WS100_MODBUS_OFFSET_TOTALFWRECTIVEENERGYT3 0x0132    // kWharh 6+2
#define WS100_MODBUS_PRECISION_TOTALFWRECTIVEENERGYT3 100.00

#define WS100_MODBUS_OFFSET_TOTALFWRECTIVEENERGYT4 0x0134    // kWharh 6+2
#define WS100_MODBUS_PRECISION_TOTALFWRECTIVEENERGYT4 100.00


#define WS100_MODBUS_OFFSET_TOTALRWRECTIVEENERGY 0x0136      // kWharh 6+2 
#define WS100_MODBUS_PRECISION_TOTALRWRECTIVEENERGY 100.00

#define WS100_MODBUS_OFFSET_TOTALRWREACTIVEENERGYT1 0x0138    // kWharh 6+2 // without tariffs version: T1=Total reverse reactive energy
#define WS100_MODBUS_PRECISION_TOTALRWRECTIVEENERGYT1 100.00

#define WS100_MODBUS_OFFSET_TOTALRWRECTIVEENERGYT2 0x013A   // kWharh 6+2
#define WS100_MODBUS_PRECISION_TOTALRWRECTIVEENERGYT2 100.00

#define WS100_MODBUS_OFFSET_TOTALRWRECTIVEENERGYT3 0x013C    // kWharh 6+2
#define WS100_MODBUS_PRECISION_TOTALRWRECTIVEENERGYT3 100.00

#define WS100_MODBUS_OFFSET_TOTALRWRECTIVEENERGYT4 0x013E    // kWharh 6+2
#define WS100_MODBUS_PRECISION_TOTALRWRECTIVEENERGYT4 100.00


#define WS100_MODBUS_OFFSET_TOTALRECTIVEENERGY 0x0140      // kWharh 6+2 
#define WS100_MODBUS_PRECISION_TOTALRECTIVEENERGY 100.00

#define WS100_MODBUS_OFFSET_TOTALREACTIVEENERGYT1 0x0142    // kWharh 6+2 // without tariffs version: T1=Total reactive energy
#define WS100_MODBUS_PRECISION_TOTALRECTIVEENERGYT1 100.00

#define WS100_MODBUS_OFFSET_TOTALRECTIVEENERGYT2 0x0144   // kWharh 6+2
#define WS100_MODBUS_PRECISION_TOTALRECTIVEENERGYT2 100.00

#define WS100_MODBUS_OFFSET_TOTALRECTIVEENERGYT3 0x0146    // kWharh 6+2
#define WS100_MODBUS_PRECISION_TOTALRECTIVEENERGYT3 100.00

#define WS100_MODBUS_OFFSET_TOTALRECTIVEENERGYT4 0x0148    // kWharh 6+2
#define WS100_MODBUS_PRECISION_TOTALRECTIVEENERGYT4 100.00

// quadrants we are ignoring, too much typing so far :D you can find addresses of the quadrants in the datasheet

#define WS100_MODBUS_OFFSET_RESSETABLE_TOTALACTIVEENERGY 0x0172    // kWh 6+2
#define WS100_MODBUS_PRECISION_RESSETABLE_TOTALACTIVEENERGY 100.00

#define WS100_MODBUS_OFFSET_RESSETABLE_TOTALREACTIVEENERGY 0x0174    // kWarh 6+2
#define WS100_MODBUS_PRECISION_RESSETABLE_TOTALREACTIVEENERGY 100.00

#define WS100_MODBUS_OFFSET_FORWARDACTIVEDEMAND 0x0176    // W 6+1
#define WS100_MODBUS_PRECISION_FORWARDACTIVEDEMAND 10.00

#define WS100_MODBUS_OFFSET_FORWARDACTIVEDEMANDMAX 0x0178    // W 6+1
#define WS100_MODBUS_PRECISION_FORWARDACTIVEDEMANDMAX 10.00

#define WS100_MODBUS_OFFSET_REVERSEACTIVEDEMAND 0x017A    // W 6+1
#define WS100_MODBUS_PRECISION_REVERSEACTIVEDEMAND 10.00

#define WS100_MODBUS_OFFSET_REVERSEACTIVEDEMANDMAX 0x017C    // W 6+1
#define WS100_MODBUS_PRECISION_REVERSEACTIVEDEMANDMAX 10.00

#define WS100_MODBUS_OFFSET_FORWARDREACTIVEDEMAND 0x0180    // var 6+1
#define WS100_MODBUS_PRECISION_FORWARDREACTIVEDEMAND 10.00

#define WS100_MODBUS_OFFSET_FORWARDREACTIVEDEMANDMAX 0x0182    // var 6+1
#define WS100_MODBUS_PRECISION_FORWARDREACTIVEDEMANDMAX 10.00

#define WS100_MODBUS_OFFSET_REVERSEREACTIVEDEMAND 0x0184    // var 6+1
#define WS100_MODBUS_PRECISION_REVERSEREACTIVEDEMAND 10.00

#define WS100_MODBUS_OFFSET_REVERSEREACTIVEDEMANDMAX 0x0186    // var 6+1
#define WS100_MODBUS_PRECISION_REVERSEREACTIVEDEMANDMAX 10.00


// 3. Meter parameters

#define WS100_MODBUS_OFFSET_SERIAL 0x01000 // 12-bit serial number,the same as DLT645 ID,it need to use 10h together, hexadecimal , 012345678910H serial number is 012345678910
#define WS100_MODBUS_OFFSET_MODBUSID 0x01003   // R/W 1-247 modbus ID
#define WS100_MODBUS_OFFSET_FIRMVAREVERSION 0x01004
#define WS100_MODBUS_OFFSET_HWVERSION 0x01005
#define WS100_MODBUS_OFFSET_FIRMWARECHECKSUM 0x01006
#define WS100_MODBUS_OFFSET_DATETIME 0x01007 // 00 year, month, day, week, hour, minute, second, need to use 10 control code to write at one time
#define WS100_MODBUS_OFFSET_CYCLEDISPLAYTIME 0x0100B  // 0-99
#define WS100_MODBUS_OFFSET_BAUDRATE 0x0100C // 1=300 2=600 3=1200 4=2400 5=4800 6=9600 7=19200 8=38400 9=115200 (Actually only 9600, 19200, 38400, 115200 are supported)
#define WS100_MODBUS_OFFSET_PARITY 0x0100D   // 0=None 1=Odd 2=even
#define WS100_MODBUS_OFFSET_STOPBIT 0x0100E  // 1=1bit 2=2bit
#define WS100_MODBUS_OFFSET_COMBINEDCODE 0x0100F  // 1=total=forward 2=total=reverse 3=total=forward+reverse 4=total=forward-reverse
#define WS100_MODBUS_OFFSET_DEMANDMODE 0x01010 // 0=Interval 1=Slip
#define WS100_MODBUS_OFFSET_DEMANDCYCLE 0x01011
#define WS100_MODBUS_OFFSET_CYCLECONTENT 0x01012 // In bitwise,0 means no display, and need use the 10 control code should to write at one time (8 bytes are used for three-phase, but only 4 bytes are used for single-phase)
#define WS100_MODBUS_OFFSET_PASSWORD 0x01016 //0000-9999
#define WS100_MODBUS_OFFSET_RUNNINGTIME 0x01018
#define WS100_MODBUS_OFFSET_TIMINGCURRENT 0x0101A
#define WS100_MODBUS_OFFSET_CLEARENERGY 0x02002   // bit12-Resettable total active energy bit13-Resettable total reactive energy
#define WS100_MODBUS_OFFSET_CLEARMAXDEMAND 0x02003 // 0xA5XX bit0=forward active maximum demand bit1=reverse active maximum demand bit2=forward active maximum demand bit3=forward active maximum demand

// 4. Tariffs parameters
//
// 1700 TP1 - 1754 TP8 (12 registers each)
// 1760 TZ table
// 176C Holidays table

#endif