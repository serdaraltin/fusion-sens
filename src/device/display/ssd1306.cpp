//
// Created by Serdar on 7.11.2024.
//
#include "device/display/ssd1306.h"
#include "config/config.h"
#include "logger/serial_logger.h"
#include <Adafruit_GFX.h>
#include "Adafruit_SSD1306.h"


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

SSD1306 *SSD1306::instance = nullptr;

SSD1306* SSD1306::getInstance()
{
     if (instance == nullptr)
         instance = new SSD1306();
        return instance;
}

SSD1306::SSD1306()
{
    while (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_I2C)) {
        ISerialLog.Warning("SSD1306 allocation failed!");
        delay(2000);
    }

    ISerialLog.Info("SSD1306 display initialized.");

}


void SSD1306::writeText(const char* text, int size, int color)
{
    display.clearDisplay();
    display.setTextColor(color? SSD1306_WHITE: SSD1306_BLACK);
    display.setCursor(0, 0);
    display.cp437(true);
    display.setTextSize(size);

    display.write(text);
    display.display();
}


void SSD1306::drawImage(const int startX, const int startY, unsigned char bitmap[], int color)
{
    display.clearDisplay();

    display.drawBitmap(
        static_cast<__int16_t>(startX),
        static_cast<__int16_t>(startY),
        bitmap,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        color);
    display.display();
}

