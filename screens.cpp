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
      break;
    case SCREEN_MENU1:
      lcd.drawstring(6, 0, "==Menu==");
      lcd.drawstring(6, 1, "Scaning frequency");
      lcd.drawstring(6, 2, "Exit");
      lcd.drawchar(0, 1 + selection, '*');
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
      lcd.drawchar(0, 1 + selection, '*');
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
