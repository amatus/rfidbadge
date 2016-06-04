#include <Wire.h>
#include "CLRC663.h"

Clrc663 rc663 = Clrc663();

void setup()
{
  Serial.begin(9600);
  Wire.begin();
}

void loop()
{
  Serial.print("PLL_Ctrl = ");
  Serial.println(rc663.read_reg(PLL_CTRL), HEX);
  Serial.print("PLL_DivOut = ");
  Serial.println(rc663.read_reg(PLL_DIVOUT), HEX);
  /* while(true) */ delay(1000);
}

/* vim: set expandtab ts=2 sw=2: */
