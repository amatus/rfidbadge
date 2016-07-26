#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <inttypes.h>

enum EEPROM_ADDRESS {
  MAGIC_ADDRESS = 0,
  SCAN_ADDRESS = 1,
  CONTRAST_ADDRESS = 2,
};

extern ST7565 lcd;
extern boolean scan; /* is scanning enabled */
extern unsigned long scan_millis; /* time between scans */

#endif

/* vim: set expandtab ts=2 sw=2: */
