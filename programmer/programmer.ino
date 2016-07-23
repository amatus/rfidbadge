/*
 * RFID Badge Programmer
 *
 * ISP wiring:
 * Programmer pin | Badge ISP pin
 * 9              | Reset
 * 11             | MOSI
 * 12             | MISO
 * 13             | SCK
 */

#include <avr/pgmspace.h>
#include <inttypes.h>
#include <SPI.h>
#include <Wire.h>
#include "Adafruit_MCP23017.h"
#include "Adafruit_RGBLCDShield.h"

/* Pins */
#define RESET (9)

/* Part signatures */
#define SIG_ATMEGA328P  (0x1E950F)
#define SIG_ATMEGA328PB (0x1E9516)

/* Flash page size in words */
#define PAGE_SIZE (64)

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*(a)))

const uint16_t PROGMEM bootstrap[] = {
#include "bootstrap.h"
};

const uint16_t PROGMEM bootloader[] = {
#include "bootloader.h"
};

const uint16_t PROGMEM program[] = {
#include "program.h"
};

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

void disp(const char *line1, const char *line2)
{
  lcd.clear();
  lcd.print(line1);
  if (line2) {
    lcd.setCursor(0, 1);
    lcd.print(line2);
  }
}

void die(const char *line1, const char *line2)
{
  disp(line1, line2);
  lcd.setBacklight(0x1);
}

uint32_t spi_transaction (uint8_t tx1, uint8_t tx2, uint8_t tx3, uint8_t tx4) {
  uint32_t rx = 0;

  SPI.transfer(tx1);
  rx = SPI.transfer(tx2);
  rx = (rx << 8) | SPI.transfer(tx3);
  rx = (rx << 8) | SPI.transfer(tx4);
  return rx;
}

boolean prog_mode() {
  pinMode(RESET, INPUT);
  delay(20);
  pinMode(RESET, OUTPUT);
  digitalWrite(RESET, LOW);
  delay(20);  
  const uint16_t rc = spi_transaction(0xAC, 0x53, 0x00, 0x00);
  return (rc >> 8) == 0x53;
}

void busy_wait() {
  uint8_t busy;

  do {
    busy = spi_transaction(0xF0, 0x00, 0x00, 0x00);
  } while(busy & 0x01);
}

void flash(uint16_t start, const uint16_t *data, uint16_t words)
{
  const uint16_t start_word = start / 2;
  const uint16_t end_word = start_word + words;
  
  for (uint16_t page = start_word; page < end_word; page += PAGE_SIZE) {
    for (uint8_t offset = 0; offset < PAGE_SIZE; ++offset) {
      uint16_t addr = page + offset;
      if (addr >= end_word) {
        break;
      }
      uint16_t w = pgm_read_word(&data[addr - start_word]);
      spi_transaction(0x40, addr >> 8, addr, w);
      spi_transaction(0x48, addr >> 8, addr, w >> 8);
    }
    spi_transaction(0x4C, page >> 8, page, 0x00);
    busy_wait();
  }
}

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setBacklight(0x7);
  disp("Detecting target", "...");
  pinMode(RESET, INPUT);
  if (digitalRead(RESET) != HIGH) {
    die("No RESET pull-up", "detected!");
    return;
  }
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV64);
  disp("Entering...", "programming mode");
  if (!prog_mode()) {
    die("programming mode", "FAILED");
    return;
  }
  disp("Reading...", "signature");
  uint32_t sig;
  sig = spi_transaction(0x30, 0x00, 0x00, 0x00) & 0xFF;
  sig = (sig << 8) | spi_transaction(0x30, 0x00, 0x01, 0x00) & 0xFF;
  sig = (sig << 8) | spi_transaction(0x30, 0x00, 0x02, 0x00) & 0xFF;
  Serial.print("sig = ");
  Serial.println(sig, HEX);
  if (sig != SIG_ATMEGA328PB && sig != SIG_ATMEGA328P) {
    char buf[7];
    
    itoa(sig >> 16, buf, 16);
    itoa(sig & 0xFFFF, &buf[2], 16);
    die("Bad Signature", buf);
    return;
  }
  disp("Erasing chip...", "");
  spi_transaction(0xAC, 0x80, 0x00, 0x00);
  busy_wait();
  if (!prog_mode()) {
    die("Erasing chip...", "FAILED");
    return;
  }
  disp("Loading...", "bootstrap code");
  flash(0x0000, bootstrap, ARRAY_SIZE(bootstrap));
  disp("Running...", "bootstrap code");
  pinMode(RESET, INPUT);
  delay(1000);
  if (!prog_mode()) {
    die("bootstrap code", "FAILED");
    return;
  }
  disp("Erasing chip...", "again");
  spi_transaction(0xAC, 0x80, 0x00, 0x00);
  busy_wait();
  if (!prog_mode()) {
    die("Erasing chip...", "again FAILED");
    return;
  }
  disp("Blowing fuses...", "");
  spi_transaction(0xAC, 0xA0, 0x00, 0xFF); /* low */
  busy_wait();
  spi_transaction(0xAC, 0xA8, 0x00, 0xDE); /* high */
  busy_wait();
  spi_transaction(0xAC, 0xA4, 0x00, 0x05); /* extended */
  busy_wait();
  disp("Loading...", "bootloader code");
  flash(0x7E00, bootloader, ARRAY_SIZE(bootloader));
  disp("Loading...", "program code");
  flash(0x0000, program, ARRAY_SIZE(program));
  disp("DONE press RESET", "for next badge");
  lcd.setBacklight(0x2);
  pinMode(RESET, INPUT);
}

void loop() {
}

/* vim: set expandtab ts=2 sw=2: */
