#include "device/display/lcd.h"
#include "config/config.h"
#include "logger/serial_logger.h"
#include "Adafruit_SSD1306.h"
#include <Adafruit_GFX.h>
#include <device/display/ssd1306.h>

#define motion_width  128
#define motion_height 64

Lcd *Lcd::instance = nullptr;

Lcd *Lcd::getInstance() {
    if(instance == nullptr)
        instance = new Lcd();
    return instance;
}

Lcd::Lcd() {
    SerialLog.Info("LCD initializing...");

    if(SSD1306::getInstance() == nullptr)
    {
        SerialLog.Error("LCD initialization failed");
    }
    SerialLog.Info("LCD initialized");



}


void Lcd::imuData() {

}
