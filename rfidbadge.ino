#include <Wire.h>
#include "CLRC663.h"
#include "ST7565.h"

#define LED  (8)
Clrc663 rc663 = Clrc663();
ST7565 lcd = ST7565(11, 13, 9, 12, 10);

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  lcd.begin(0x18);
  lcd.drawstring(0, 0, "Scanning...");
  lcd.display();
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
  if (rc == 2) {
    digitalWrite(LED, HIGH);
    char buf[2];
    itoa(atqa[0], buf, 16);
    lcd.drawstring(0, 1, buf);
    itoa(atqa[1], buf, 16);
    lcd.drawstring(0, 2, buf);
  } else {
    digitalWrite(LED, LOW);
    lcd.drawstring(0, 1, "  ");
    lcd.drawstring(0, 2, "  ");
  }
  lcd.display();
  delay(1000);
}

/* vim: set expandtab ts=2 sw=2: */
