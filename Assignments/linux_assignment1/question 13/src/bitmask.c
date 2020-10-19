#include "bitmask.h"
uint8_t setbit(uint8_t num,uint8_t position)
{
  num |=(1 <<position);
  return num;
}


uint8_t clearbit(uint8_t num,uint8_t position)
{
  num &= ~(1 <<position);
  return num;
}

uint8_t flipbit(uint8_t num,uint8_t position)
{
  num ^= (1 <<position);
  return num;
}

_Bool querybit(uint8_t num,uint8_t position)
{
  if(num & (1<<position-1))
    return true;
  else
    return false;
}
