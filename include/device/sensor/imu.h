//
// Created by Serdar on 6.11.2024.
//

#ifndef FUSION_SENS_IMU_H
#define FUSION_SENS_IMU_H


#define IIMU IMU::getInstance()

#include "Adafruit_MPU6050.h"

class IMU {
private:
    static IMU *instance;
public:
    IMU();
    static IMU &getInstance()
    {
        static IMU instance;
        return instance;
    }
    Adafruit_MPU6050 sensor;

};


#endif //FUSION_SENS_IMU_H
