#include "comm.h"
#include "manager/screen.h"
#include "device/sensor/imu.h"
#include "comms/i2c.h"
#include "device/display/ssd1306.h"
#include "logger/serial_logger.h"
#include "manager/wifi.h"

#include <Arduino.h>
#include <device/sensor/bmp180.h>
#include <iomanip>
#include <sstream>

void initialize()
{
    Serial.begin(BOUD_RATE);

    //Communication
    SerialLogger::getInstance();
    I2C::getInstance();

    //Device
    SSD1306::getInstance();
    IMU::getInstance();
    bmp180::getInstance();

    //Manager
    SCREEN::getInstance();
    WiFiManager::getInstance();
}

void test(){

}

//#ifndef  UNIT_TEST
void setup() {

    initialize();
    IWiFi.connect();

    delay(1000);

    for (const WifiInfo& network: IWiFi.scanNetworks())
    {
        SerialLog.Info(network.to_string().c_str());
    }
    test();
}

std::string formatFloat(const float value, const int width = 6) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << std::setw(width) << value;
    return ss.str();
}

void loop() {
    delay(100);

/*
    sensors_event_t acc, gyro, temp;
    IIMU.sensor.getEvent(&acc, &gyro, &temp);

    std::stringstream ss;

    ss << " ACC     GYRO     ENV\n";
    ss << formatFloat(acc.acceleration.x) << " "
       << formatFloat(gyro.gyro.x)        << "  "
       << formatFloat(IBMP180.bmp.readTemperature()) << "\n";

    ss << formatFloat(acc.acceleration.y) << " "
       << formatFloat(gyro.gyro.y)        << "  "
       << formatFloat(IBMP180.bmp.readPressure()/1000.0) << "\n";

    ss << formatFloat(acc.acceleration.z) << " "
       << formatFloat(gyro.gyro.z)        << "  "
       << formatFloat(IBMP180.bmp.readAltitude()/10.0) << "\n";

    ISCREEN.text(ss.str());

*/

    //WiFi.scanDelete();

    // Wait a bit before scanning again.
    delay(5000);
}

//#endif