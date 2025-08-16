#include "config/config.h"
#include "config/bitmap.h"
#include "device/display/lcd.h"
#include "logger/serial_logger.h"
#include <Adafruit_GFX.h>
#include <device/display/ssd1306.h>

Lcd *Lcd::instance = nullptr;

Lcd *Lcd::getInstance() {
    if(instance == nullptr)
        instance = new Lcd();
    return instance;
}

Lcd::Lcd() {
    SerialLog.Info("LCD initializing...");
    //fill
    SerialLog.Info("LCD initialized");

    if(BOOT_LOGO){
        image(LOGO);
    }
}

void Lcd::text(const char* text)
{
    ISSD1306->writeText(text, 1, 1);
}

void Lcd::textM(const char* text)
{
    ISSD1306->writeText(text, 1, 1);
}

void Lcd::image(unsigned char bitmap[])
{
    ISSD1306->drawBitmap(bitmap);
}

void Lcd::image(unsigned char bitmap[], int color)
{
}

void Lcd::image(int startX, int startY, unsigned char bitmap[], int color)
{
}
