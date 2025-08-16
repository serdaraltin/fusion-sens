#include "config/config.h"
#include "manager/screen.h"
#include "device/sensor/imu.h"
#include "comms/i2c.h"

#include <Arduino.h>
#include <device/display/ssd1306.h>
#include <logger/serial_logger.h>

void initialize()
{
    Serial.begin(BOUD_RATE);

    //Communication
    SerialLogger::getInstance();
    I2C::getInstance();

    //Device
    SSD1306::getInstance();
    IMU::getInstance();

    //Manager
    SCREEN::getInstance();

}

void test(){
    Serial.begin(BOUD_RATE);
}

#ifndef  UNIT_TEST
void setup() {

    initialize();

    test();
}

void loop() {
    delay(5000);
}

#endif