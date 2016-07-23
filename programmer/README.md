This sketch is for an Arduino Uno with an Adafruit RGB LCD Shield[0]
and an ISP connector for programming blank RFID badges.

The ISP connector is wired:

|Arduino pin | ISP connector pin|
|------------|------------------|
|9           | RESET            |
|11          | MOSI             |
|12          | MISO             |
|13          | SCK              |
|GND         | GND              |
|5V          | VCC              |

When the sketch runs it will detect a connected badge by the pull-up
resistor on the RESET pin, then it will program the badge. If anything
goes wrong the backlight will turn red and a message displayed. Otherwise
the backlight will turn green and the badge may be unplugged. To program
the next badge, plug it in and press Reset on the LCD Shield.

  [0]: https://www.adafruit.com/products/716
