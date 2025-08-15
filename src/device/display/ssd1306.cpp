//
// Created by Serdar on 7.11.2024.
//

#include "device/display/ssd1306.h"
#include "config/config.h"
#include "logger/serial_logger.h"
#include "config/bitmap.h"

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
        SerialLog.Warning("SSD1306 allocation failed!");
        delay(2000);
    }
    SerialLog.Info("SSD1306 allocation successful.");

    if(BOOT_LOGO){
        display.clearDisplay();
        display.display();
        image(LOGO);
        SerialLog.Info("SSD1306 display initialized.");
    }
}

void SSD1306::textInit()
{
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.cp437(true);
}

void SSD1306::textWrite(const char* text, int size)
{
    textInit();
    display.setTextSize(1);

    display.write(text);
    display.display();
}

void SSD1306::text(const char* text)
{
    textWrite(text, 1);
}

void SSD1306::textM(const char* text)
{
    textWrite(text, 2);
}

void SSD1306::image(unsigned char bitmap[])
{
    display.clearDisplay();

    display.drawBitmap(0,0,
        bitmap,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        1);

    display.display();
    delay(1000);
}
void SSD1306::image(unsigned char bitmap[], int color)
{
    display.clearDisplay();

    display.drawBitmap(0,0,
        bitmap,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        color);

    display.display();
    delay(1000);
}
void SSD1306::image(const int startX, const int startY, unsigned char bitmap[], int color)
{
    display.clearDisplay();

    display.drawBitmap(static_cast<__int16_t>(startX), static_cast<__int16_t>(startY),
        bitmap,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        color);

    display.display();
    delay(1000);
}

