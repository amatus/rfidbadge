#include <Wire.h>
#include "CLRC663.h"

Clrc663::Clrc663(uint8_t address) : addr(address)
{
}

uint8_t Clrc663::read_reg(uint8_t reg)
{
  Wire.beginTransmission(addr);
  Wire.write(reg);
  Wire.endTransmission();
  Wire.requestFrom(addr, (uint8_t)1);
  return Wire.read();
}

void Clrc663::write_reg(uint8_t reg, uint8_t val)
{
  Wire.beginTransmission(addr);
  Wire.write(reg);
  Wire.write(val);
  Wire.endTransmission();
}
