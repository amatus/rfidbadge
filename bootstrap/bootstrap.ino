/* This sketch programs the CLRC663 to generate a ~16 MHz signal on CLKOUT.
 * This can be loaded onto the ATMEGA over ISP before the Arduino bootloader,
 * which requires the 16 MHz external clock to function. Loading the Arduino
 * bootloader also programs the efuses which configures the ATMEGA to use
 * the external 16 MHz clock.
 *
 * To load this sketch with an ISP programmer other than one supported by the
 * Arduino IDE, use this avrdude command:
 *     avrdude -c <programmer-id> -P <port> -p m328p -v \
 *         -Uflash:w:bootstrap.hex
 */

#include <Wire.h>

#define LED    (8)
#define ADDR   (0x2A)

void write_eeprom(int addr, int val)
{
  /* flush FIFO */
  Wire.beginTransmission(ADDR);
  Wire.write(0x02);
  Wire.write(0x10);
  Wire.endTransmission();
  /* load FIFO with addr-hi, addr-lo, data */
  Wire.beginTransmission(ADDR);
  Wire.write(0x05);
  Wire.write(addr >> 8);
  Wire.write(addr & 0xFF);
  Wire.write(val);
  Wire.endTransmission();
  /* WriteE2 command */
  Wire.beginTransmission(ADDR);
  Wire.write(0x00);
  Wire.write(0x08);
  Wire.endTransmission();
}

void setup()
{
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  Wire.begin();
  /* Set initial value of PLL_Ctrl to enable the PLL and wire it to CLKOUT
   * and set the VCO frequency to 366 MHz */
  write_eeprom(0x7D, 0x19);
  /* Set initial value of PLLDiv_out to 23: 366 MHZ / 23 = 15.913 MHz */
  write_eeprom(0x7E, 0x17);
  /* SoftReset command */
  Wire.beginTransmission(ADDR);
  Wire.write(0x00);
  Wire.write(0x1F);
  Wire.endTransmission();
  digitalWrite(LED, LOW);
}

void loop()
{
}


