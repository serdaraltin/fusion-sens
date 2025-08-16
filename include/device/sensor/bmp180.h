//
// Created by Serdar on 7.11.2024.
//

#ifndef FUSION_SENS_BMP180_H
#define FUSION_SENS_BMP180_H
#include <Adafruit_BMP085.h>

#define IBMP180 bmp180::getInstance()

class bmp180 {
private:
    static bmp180 *instance;
public:
    bmp180();
    ~bmp180() = default;

    static bmp180 &getInstance()
    {
        static bmp180 instance;
        return instance;
    }

    Adafruit_BMP085 bmp;
};


#endif //FUSION_SENS_BMP180_H
