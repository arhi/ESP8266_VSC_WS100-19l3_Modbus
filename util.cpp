#include <Arduino.h>
#include "util.h"

float dword2float(uint16_t hibyte, uint16_t lobyte){
  float temp = 0;
  uint16_t *t;
  t = (uint16_t *) &temp;
  t[0] = hibyte;
  t[1] = lobyte;
  return temp;
}

// x^16 + x^15 + x^2 + 1 (0xA001)
uint16_t crc16_update(uint16_t crc, uint8_t a)
{
  int i;

  crc ^= a;
  for (i = 0; i < 8; ++i)
  {
    if (crc & 1)
      crc = (crc >> 1) ^ 0xA001;
    else
      crc = (crc >> 1);
  }

  return crc;
}

void printLocalTime(Stream *_stream_ptr)
{
  //time_t rawtime;
  //struct tm * timeinfo;
  char buffer[80];

  //time (&rawtime);
  //timeinfo = localtime(&rawtime);
  //strftime(buffer, 80, " %d %B %Y %H:%M:%S ", timeinfo);
  printLocalTime(buffer, 80);
  _stream_ptr->println(buffer);
}

void printLocalTime(char *buffer, size_t maxlen)
{
  time_t rawtime;
  struct tm * timeinfo;

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer, maxlen, " %d %B %Y %H:%M:%S ", timeinfo);
}