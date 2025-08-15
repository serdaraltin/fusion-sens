#include "device/display/lcd.h"
#include "config/config.h"
#include "config/bitmap.h"
#include "logger/serial_logger.h"

#include <esp32-hal.h>
#include <device/display/ssd1306.h>

Lcd *Lcd::instance = nullptr;

Lcd *Lcd::getInstance() {
    if(instance == nullptr)
        instance = new Lcd();
    return instance;
}

Lcd::Lcd() {
    ISerialLog.Info("LCD initializing...");

    while(!ISsd1306)
    {
        ISerialLog.Error("LCD initialization failed!");
        delay(1000);
    }
    ISerialLog.Info("LCD initialized");

    if(BOOT_LOGO)
    {
        image(LOGO);
    }
}

void Lcd::text(const char* text)
{

    ISsd1306->writeText(text, 1, 1);
}

void Lcd::textM(const char* text)
{
    ISsd1306->writeText(text, 2, 1);
}

void Lcd::image(unsigned char bitmap[])
{
    ISsd1306->drawImage(0,0,bitmap, 1);
}

void Lcd::image(unsigned char bitmap[], const int color)
{
    ISsd1306->drawImage(0,0,bitmap, color);
}

void Lcd::image(const int startX, const int startY, unsigned char bitmap[], const int color)
{
    ISsd1306->drawImage(startX,startY,bitmap, color);
}
