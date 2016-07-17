#include <Arduino.h>
#include "ST7565.h"
#include "screens.h"

ST7565 lcd = ST7565(11, 13, 9, 12, 10);
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
      lcd.drawstring(6, 1, "Sub-menu");
      lcd.drawstring(6, 2, "Exit");
      lcd.drawstring(0, 1 + selection, "*");
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
      if (selection == 1) {
        screen = SCREEN_SCANNING;
      }
      break;
    default:
      break; /* do nothing */
  }
  display_screen(screen, selection);
  trigger_led();
}

/* vim: set expandtab ts=2 sw=2: */
