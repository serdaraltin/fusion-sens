#include "config/config.h"
#include "logger/serial_logger.h"
#include "device/device_manager.h"
#include "device/display/lcd.h"
#include "device/sensor/imu.h"
#include "comms/i2c.h"
#include "helper/hex.h"

#include <Arduino.h>
#include <Wire.h>
#include <device/display/ssd1306.h>


void initialize(){
    Serial.begin(BOUD_RATE);

    DeviceManager::getInstance();

    I2C::getInstance();
    SSD1306::getInstance();
    Lcd::getInstance();
    IMU::getInstance();

    Hex::getInstance();
    SerialLogger::getInstance();
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