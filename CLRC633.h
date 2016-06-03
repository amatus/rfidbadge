#ifndef _CLRC633_H_
#define _CLRC633_H_

#include <inttypes.h>

#define DRV_MOD     (0x28)
#define PLL_CTRL    (0x3d)
#define PLL_DIVOUT  (0x3e)

class Clrc633 {
  private:
    uint8_t addr;
  public:
    Clrc633(uint8_t address = 0x2a);
    uint8_t read_reg(uint8_t reg);
    void write_reg(uint8_t reg, uint8_t val);
};

#endif
