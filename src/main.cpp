#include <SPI.h>
#include <Wire.h>

#include "config/config.h"
#include "logger/serial_logger.h"

#include "device/device_manager.h"
#include "device/display/lcd.h"
#include "device/sensor/imu.h"
#include <Arduino.h>

#include "comms/i2c.h"
#include "helper/hex.h"


void initialize(){
    Serial.begin(BOUD_RATE);
    Hex::getInstance();
    SerialLogger::getInstance();
    DeviceManager::getInstance();
    I2C::getInstance();
    Lcd::getInstance();
    IMU::getInstance();
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