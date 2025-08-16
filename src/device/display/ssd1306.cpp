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

