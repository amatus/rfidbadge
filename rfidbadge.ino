#include <Wire.h>
#include "CLRC663.h"
#include "ST7565.h"

#define LED    (8)
#define MENU   (3)
#define SELECT (4)
Clrc663 rc663 = Clrc663();
ST7565 lcd = ST7565(11, 13, 9, 12, 10);

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(MENU, INPUT_PULLUP);
  pinMode(SELECT, INPUT_PULLUP);
  Serial.begin(9600);
  lcd.begin(0x08);
  Wire.begin();
}

void loop()
{
  lcd.clear();
  lcd.drawstring(0, 0, "Scanning...");
  rc663.iso_14443A_init();
  int rc;
  {
    Serial.println("Requesting ATQA");
    uint8_t atqa[2];
    rc663.transmit_enable(true);
    rc = rc663.iso_14443A_reqa(atqa);
    Serial.print("rc = ");
    Serial.println(rc);
    Serial.print("ATQA = ");
    Serial.print(atqa[0], HEX);
    Serial.print(", ");
    Serial.println(atqa[1], HEX);
  }
  if (rc == 2) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
    goto out;
  }
  {
    Serial.println("Selecting");
    uint8_t uid[10];
    rc = rc663.iso_14443A_select(uid);
    Serial.print("rc = ");
    Serial.println(rc);
    lcd.drawstring(0, 1, "ID:");
    char buf[3];
    for (int i = 0; i < rc; ++i) {
      Serial.print(uid[i], HEX);
      Serial.print(" ");
      if (uid[i] < 0x10) {
        buf[0] = '0';
        itoa(uid[i], &buf[1], 16);
      } else {
        itoa(uid[i], buf, 16);
      }
      lcd.drawstring(i * 3 * 6, 2, buf);
    }
    Serial.print("\n");
  }
out:
  rc663.transmit_enable(false);
  lcd.display();
  delay(1000);
}

/* vim: set expandtab ts=2 sw=2: */
