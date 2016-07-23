#include <Arduino.h>
#include "EEPROM.h"
#include "ST7565.h"
#include "globals.h"
#include "screens.h"

Screen screen; /* which screen are we on */
uint8_t selection; /* which menu item is selected */
boolean scan; /* is scanning enabled */
unsigned long last_led; /* last time the led was turned on */

void trigger_led()
{
  digitalWrite(LED, HIGH);
  last_led = millis();
}

void display_screen(Screen screen, uint8_t selection)
{
  lcd.clear();
  switch (screen) {
    case SCREEN_SCANNING:
      lcd.drawstring(0, 0, scan ? (char *)"Scanning..." : (char *)"Not scanning!");
      /* Special characters
      lcd.drawstring(0, 1, "\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f");
      lcd.drawstring(0, 2, "\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f");
      lcd.drawstring(0, 3, "\x20\x21\x22\x23\x24\x25\x26\x27\x28\x29\x2a\x2b\x2c\x2d\x2e\x2f");
      */
      break;
    case SCREEN_MENU1:
      lcd.drawstring(6, 0, "==Menu==");
      lcd.drawstring(6, 1, "Scaning frequency");
      lcd.drawstring(6, 2, "Exit");
      lcd.drawchar(0, 1 + selection, '\x10');
      break;
    case SCREEN_FREQUENCY:
      lcd.drawstring(6, 0, "=Scanning frequency=");
      if (0 == scan_millis) {
        lcd.drawstring(6, 1, "Disabled");
      } else {
        lcd.drawchar(6, 1, '0' + scan_millis / 1000);
        lcd.drawchar(12, 1, '.');
        lcd.drawchar(18, 1, '0' + scan_millis / 100 % 10);
        lcd.drawstring(24, 1, " second(s)");
      }
      lcd.drawstring(6, 2, "+ 0.1 seconds");
      lcd.drawstring(6, 3, "- 0.1 seconds");
      lcd.drawchar(0, 1 + selection, '\x10');
      break;
  }
  lcd.display();
}

void button_transition(Button button)
{
  switch (screen | button) { /* Act on screen ⨯ button */
    case SCREEN_SCANNING | MENU_BUTTON:
      screen = SCREEN_MENU1; /* goto menu1 */
      selection = 0;
      break;
    case SCREEN_MENU1 | MENU_BUTTON:
      selection = (selection + 1) % 2;
      break;
    case SCREEN_MENU1 | SELECT_BUTTON:
      switch (selection) {
        case 0:
          screen = SCREEN_FREQUENCY;
          selection = 0;
          break;
        case 1:
          screen = SCREEN_SCANNING;
          break;
      }
      break;
    case SCREEN_FREQUENCY | MENU_BUTTON:
      selection = (selection + 1) % 3;
      break;
    case SCREEN_FREQUENCY | SELECT_BUTTON:
      switch (selection) {
        case 0:
          EEPROM.write(1, scan_millis / 100);
          scan = 0 != scan_millis;
          screen = SCREEN_MENU1;
          selection = 0;
          break;
        case 1:
          scan_millis += 100;
          if (scan_millis >= 10000) {
            scan_millis = 9900;
          }
          break;
        case 2:
          if (0 != scan_millis) {
            scan_millis -= 100;
          }
          break;
      }
      break;
    default:
      break; /* do nothing */
  }
  display_screen(screen, selection);
  trigger_led();
}

/* vim: set expandtab ts=2 sw=2: */
