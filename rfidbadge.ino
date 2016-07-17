#include <EEPROM.h>
#include <Wire.h>
#include "CLRC663.h"
#include "ST7565.h"
#include "screens.h"

#define MENU   (3)
#define SELECT (4)
#define EEPROM_MAGIC  (0xDB)
#define DEFAULT_SCAN_DECISECONDS  (10)

Clrc663 rc663 = Clrc663();
unsigned long scan_millis; // time between scans
unsigned long last_scan;   // last time scanned


void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(MENU, INPUT_PULLUP);
  pinMode(SELECT, INPUT_PULLUP);
  Serial.begin(9600);
  lcd.begin(0x08);
  Wire.begin();
  byte magic = EEPROM.read(0);
  if (EEPROM_MAGIC != magic) {
    EEPROM.write(0, EEPROM_MAGIC);
    EEPROM.write(1, DEFAULT_SCAN_DECISECONDS);
    scan_millis = DEFAULT_SCAN_DECISECONDS * 100;
  } else {
    scan_millis = EEPROM.read(1) * 100;
  }
  last_scan = millis() - scan_millis;
  scan = 0 != scan_millis;
  display_screen(SCREEN_SCANNING, 0);
  trigger_led();
}

void do_scan()
{
  int rc;
  rc663.iso_14443A_init();
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
    trigger_led();
  } else {
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
}

void loop()
{
  /* Do scan if it's time */
  if (screen == SCREEN_SCANNING && scan && millis() - last_scan >= scan_millis) {
    last_scan = millis();
    do_scan();
  }
  /* Turn off backlight if it's time */
  if (digitalRead(LED) == HIGH && millis() - last_led >= LED_MILLIS) {
    digitalWrite(LED, LOW);
  }
  /* Read switches, do edge detection */
  static boolean select_pressed, menu_pressed; /* previous state of the buttons */
  bool select = digitalRead(SELECT) == LOW;
  bool menu = digitalRead(MENU) == LOW;
  if (!select_pressed && select) {
    button_transition(SELECT_BUTTON);
  }
  if (!menu_pressed && menu) {
    button_transition(MENU_BUTTON);
  }
  select_pressed = select;
  menu_pressed = menu;
}

/* vim: set expandtab ts=2 sw=2: */
