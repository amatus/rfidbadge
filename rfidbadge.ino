#include <EEPROM.h>
#include <Wire.h>
#include "CLRC663.h"
#include "ST7565.h"
#include "globals.h"
#include "screens.h"

#define MENU   (3)
#define SELECT (4)
#define EEPROM_MAGIC  (0xDB)
#define DEFAULT_SCAN_DECISECONDS  (10)
#define DEFAULT_CONTRAST  (8)
#define LONG_PRESS_MILLIS (500)

ST7565 lcd = ST7565(11, 13, 9, 12, 10);
Clrc663 rc663 = Clrc663();

unsigned long scan_millis; /* time between scans */
unsigned long last_scan;   /* last time scanned */

void change_contrast(int delta)
{
  int contrast = EEPROM.read(CONTRAST_ADDRESS) + delta;

  if (contrast < 1) {
    contrast = 1;
  } else if (contrast > 63) {
    contrast = 63;
  }
  EEPROM.write(CONTRAST_ADDRESS, contrast);
  lcd.st7565_set_brightness(contrast);
}

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(MENU, INPUT_PULLUP);
  pinMode(SELECT, INPUT_PULLUP);
  Serial.begin(9600);
  Wire.begin();
  uint8_t contrast = DEFAULT_CONTRAST;
  uint8_t magic = EEPROM.read(MAGIC_ADDRESS);
  if (EEPROM_MAGIC != magic) {
    EEPROM.write(MAGIC_ADDRESS, EEPROM_MAGIC);
    EEPROM.write(SCAN_ADDRESS, DEFAULT_SCAN_DECISECONDS);
    EEPROM.write(CONTRAST_ADDRESS, contrast);
    scan_millis = DEFAULT_SCAN_DECISECONDS * 100;
  } else {
    scan_millis = EEPROM.read(SCAN_ADDRESS) * 100;
    contrast = EEPROM.read(CONTRAST_ADDRESS);
  }
  last_scan = millis() - scan_millis;
  scan = 0 != scan_millis;
  lcd.begin(contrast);
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
  static unsigned long select_millis, menu_millis; /* when the button was pressed */
  boolean select = digitalRead(SELECT) == LOW;
  boolean menu = digitalRead(MENU) == LOW;
  if (select) {
    if (!select_pressed) {
      select_millis = millis();
      button_transition(SELECT_BUTTON);
    } else if (millis() - select_millis >= LONG_PRESS_MILLIS) {
      select_millis = millis();
      change_contrast(2);
    }
  }
  if (menu) {
    if (!menu_pressed) {
      menu_millis = millis();
      button_transition(MENU_BUTTON);
    } else if (millis() - menu_millis >= LONG_PRESS_MILLIS) {
      menu_millis = millis();
      change_contrast(-2);
    }
  }
  select_pressed = select;
  menu_pressed = menu;
}

/* vim: set expandtab ts=2 sw=2: */
