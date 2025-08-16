//
// Created by Serdar on 5.11.2024.
//

#include "logger/serial_logger.h"
#include "config/config.h"
#include <string>
#include <Arduino.h>


SerialLogger *SerialLogger::instance = nullptr;


SerialLogger::SerialLogger() {
    setLevel(LOG_LEVEL);
    Logger::Log.Info("Serial Bound Rate=%d", BOUD_RATE);
    while (!Serial){
        delay(10);
    }
    Logger::Log.Info("Serial Logger initialized.");
}

std::string SerialLogger::log2String(Logger::Level level, const std::string &message) {
    std::string output = Logger::log2String(level, message);
    Serial.println(output.c_str());
    return output;
}
