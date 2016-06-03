#include <Wire.h>
#include "CLRC633.h"

Clrc633::Clrc633(uint8_t address) : addr(address)
{
}

uint8_t Clrc633::read_reg(uint8_t reg)
{
  Wire.beginTransmission(addr);
  Wire.write(reg);
  Wire.endTransmission();
  Wire.requestFrom(addr, (uint8_t)1);
  return Wire.read();
}

void Clrc633::write_reg(uint8_t reg, uint8_t val)
{
  Wire.beginTransmission(addr);
  Wire.write(reg);
  Wire.write(val);
  Wire.endTransmission();
}
