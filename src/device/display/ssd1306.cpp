//
// Created by Serdar on 7.11.2024.
//

#include "device/display/ssd1306.h"
#include "logger/serial_logger.h"
#include "config.h"

#include <Adafruit_GFX.h>
#include "Adafruit_SSD1306.h"


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

SSD1306 *SSD1306::instance = nullptr;

SSD1306::SSD1306()
{
    while (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_I2C)) {
        delay(2000);
    }
}

void SSD1306::testanimate()
{
#define NUMFLAKES     10 // Number of snowflakes in the animation example

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16
    static const unsigned char PROGMEM logo_bmp[] =
    { 0b00000000, 0b11000000,
      0b00000001, 0b11000000,
      0b00000001, 0b11000000,
      0b00000011, 0b11100000,
      0b11110011, 0b11100000,
      0b11111110, 0b11111000,
      0b01111110, 0b11111111,
      0b00110011, 0b10011111,
      0b00011111, 0b11111100,
      0b00001101, 0b01110000,
      0b00011011, 0b10100000,
      0b00111111, 0b11100000,
      0b00111111, 0b11110000,
      0b01111100, 0b11110000,
      0b01110000, 0b01110000,
      0b00000000, 0b00110000 };
#define XPOS   0 // Indexes into the 'icons' array in function below
#define YPOS   1
#define DELTAY 2

    int8_t f, icons[NUMFLAKES][3];

    // Initialize 'snowflake' positions
    for(f=0; f< NUMFLAKES; f++) {
        icons[f][XPOS]   = random(1 - LOGO_WIDTH, display.width());
        icons[f][YPOS]   = -LOGO_HEIGHT;
        icons[f][DELTAY] = random(1, 6);
        Serial.print(F("x: "));
        Serial.print(icons[f][XPOS], DEC);
        Serial.print(F(" y: "));
        Serial.print(icons[f][YPOS], DEC);
        Serial.print(F(" dy: "));
        Serial.println(icons[f][DELTAY], DEC);
    }

    for(;;) { // Loop forever...
        display.clearDisplay(); // Clear the display buffer

        // Draw each snowflake:
        for(f=0; f< NUMFLAKES; f++) {
            display.drawBitmap(icons[f][XPOS], icons[f][YPOS], logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, SSD1306_WHITE);
        }

        display.display(); // Show the display buffer on the screen
        delay(200);        // Pause for 1/10 second

        // Then update coordinates of each flake...
        for(f=0; f< NUMFLAKES; f++) {
            icons[f][YPOS] += icons[f][DELTAY];
            // If snowflake is off the bottom of the screen...
            if (icons[f][YPOS] >= display.height()) {
                // Reinitialize to a random position, just off the top
                icons[f][XPOS]   = random(1 - LOGO_WIDTH, display.width());
                icons[f][YPOS]   = -LOGO_HEIGHT;
                icons[f][DELTAY] = random(1, 6);
            }
        }
    }
}

void SSD1306::writeText(const char* text, const int size, const int color)
{
    display.clearDisplay();
    display.setTextColor(color);
    display.setTextSize(size);
    display.setCursor(0, 0);
    display.print(text);
    display.display();
}
void SSD1306::drawBitmap(unsigned char bitmap[])
{
    display.clearDisplay();

    display.drawBitmap(0,0,
        bitmap,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        1);

    display.display();
    delay(1000);
}
void SSD1306::drawBitmap(unsigned char bitmap[], int color)
{
    display.clearDisplay();

    display.drawBitmap(0,0,
        bitmap,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        color);

    display.display();
    delay(1000);
}
void SSD1306::drawBitmap(const int startX, const int startY, unsigned char bitmap[], int color)
{
    display.clearDisplay();

    display.drawBitmap(static_cast<__int16_t>(startX), static_cast<__int16_t>(startY),
        bitmap,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        color);

    display.display();
    delay(1000);
}

