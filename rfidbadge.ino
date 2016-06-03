#include <Wire.h>
#include "CLRC633.h"

Clrc633 rc633 = Clrc633();

void setup()
{
  Serial.begin(9600);
  Wire.begin();
}

void loop()
{
  Serial.print("PLL_Ctrl = ");
  Serial.println(rc633.read_reg(PLL_CTRL), HEX);
  Serial.print("PLL_DivOut = ");
  Serial.println(rc633.read_reg(PLL_DIVOUT), HEX);
  /* while(true) */ delay(1000);
}
