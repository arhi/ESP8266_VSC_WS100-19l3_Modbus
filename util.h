#ifndef _UTIL_H_
#define _UTIL_H_

float dword2float(uint16_t hibyte, uint16_t lobyte);

void printLocalTime(Stream *);
void printLocalTime(char *, size_t);

uint16_t crc16_update(uint16_t crc, uint8_t a);

static inline uint16_t lowWord(uint32_t ww)
{
  return (uint16_t) ((ww) & 0xFFFF);
}

static inline uint16_t highWord(uint32_t ww)
{
  return (uint16_t) ((ww) >> 16);
}


#endif
