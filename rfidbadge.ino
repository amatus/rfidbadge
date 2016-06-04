#include <Wire.h>
#include "CLRC663.h"

Clrc663 rc663 = Clrc663();

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  rc663.iso_14443A_init();
}

void loop()
{
  rc663.transmit_enable(true);
  uint8_t atqa[2];
  int rc = rc663.iso_14443A_reqa(atqa);
  rc663.transmit_enable(false);
  Serial.print("rc = ");
  Serial.println(rc);
  Serial.print("atqa = ");
  Serial.print(atqa[0], HEX);
  Serial.print(", ");
  Serial.println(atqa[1], HEX);
  delay(1000);
}

/* vim: set expandtab ts=2 sw=2: */
