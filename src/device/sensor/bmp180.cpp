//
// Created by Serdar on 7.11.2024.
//

#include "device/sensor/bmp180.h"

#include <logger/serial_logger.h>

bmp180 *bmp180::instance = nullptr;

[[noreturn]] bmp180::bmp180()
{
    if(!bmp.begin())
    {
        SerialLog.Error("BMP180 initialization failed!");
        while(1){}
    }
}
