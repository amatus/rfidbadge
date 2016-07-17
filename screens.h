#ifndef _SCREENS_H_
#define _SCREENS_H_

#include <inttypes.h>

enum Button : uint8_t {
  MENU_BUTTON = 0,
  SELECT_BUTTON = 1,
};

enum Screen : uint8_t {
  SCREEN_SCANNING = 0 << 1,
  SCREEN_MENU1 = 1 << 1,
};

extern ST7565 lcd;
extern Screen screen; /* which screen are we on */
extern uint8_t selection; /* which menu item is selected */
extern boolean scan; /* is scanning enabled */
extern unsigned long last_led; /* last time the led was turned on */
#define LED_MILLIS (5 * 1000)  /* time to leave the led on */
#define LED (8) /* LED pin */

void trigger_led();
void display_screen(Screen screen, uint8_t selection);
void button_transition(Button button);

#endif

/* vim: set expandtab ts=2 sw=2: */
