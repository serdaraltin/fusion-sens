//
// Created by Serdar on 6.11.2024.
//

#include "device/sensor/imu.h"
#include "logger/serial_logger.h"
#include "config/config.h"
#include "comms/i2c.h"
#include "helper/hex.h"
#include "Adafruit_MPU6050.h"

Adafruit_MPU6050 sensor;

IMU *IMU::instance = nullptr;

IMU *IMU::getInstance() {
    if(instance == nullptr)
        instance = new IMU();
    return instance;
}

IMU::IMU() {
    SerialLog.Info("%s testing...", SENSOR_NAME);

    int check = I2CI->checkDevice(SENSOR_I2C);
    SerialLog.Info("I2C Device checked. Device=%s Result=%s",
                   HexI->int2Hex(SENSOR_I2C).c_str(), (check == 0) ? "Available" : "Not Found!" );

    if(!sensor.begin()){
        SerialLog.Warning("%s not found !", SENSOR_NAME);
        while(FIND_REPEAT){
            delay(10);
        }
    }
    SerialLog.Info("%s found.", SENSOR_NAME);

    sensor.setHighPassFilter(MPU6050_HIGHPASS_0_63_HZ);
    sensor.setMotionDetectionThreshold(1);
    sensor.setMotionDetectionDuration(20);
    sensor.setInterruptPinLatch(true);
    sensor.setMotionInterrupt(true);

    SerialLog.Info("%s initialized.", SENSOR_NAME);
}

