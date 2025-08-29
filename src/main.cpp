#include "config.h"
#include "manager/screen.h"
#include "device/sensor/imu.h"
#include "comms/i2c.h"
#include "device/display/ssd1306.h"
#include "logger/serial_logger.h"

#include <Arduino.h>
#include <iomanip>
#include <sstream>
#include <comms/wifi_manager.h>
#include <device/sensor/bmp180.h>

#include "WiFi.h"

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

#ifndef  UNIT_TEST
void setup() {

    initialize();
    IWiFi.connectWiFi();

    SerialLog.Info(IWiFi.getWiFiInfo().ip.c_str());

    delay(1000);
    test();
}

std::string formatFloat(const float value, const int width = 6) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << std::setw(width) << value;
    return ss.str();
}

void loop() {

   /* WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);

    int n = WiFi.scanNetworks();

    for (int i = 0; i < n; i++)
    {
        Serial.printf("%2d",i + 1);
        Serial.print(" | ");
        Serial.printf("%-32.32s", WiFi.SSID(i).c_str());
        Serial.print(" | ");
        Serial.printf("%4d", WiFi.RSSI(i));
        Serial.print(" | ");
        Serial.printf("%2d", WiFi.channel(i));
        Serial.print(" | ");
        switch (WiFi.encryptionType(i))
        {
        case WIFI_AUTH_OPEN:
            Serial.print("open");
            break;
        case WIFI_AUTH_WEP:
            Serial.print("WEP");
            break;
        case WIFI_AUTH_WPA_PSK:
            Serial.print("WPA");
            break;
        case WIFI_AUTH_WPA2_PSK:
            Serial.print("WPA2");
            break;
        case WIFI_AUTH_WPA_WPA2_PSK:
            Serial.print("WPA+WPA2");
            break;
        case WIFI_AUTH_WPA2_ENTERPRISE:
            Serial.print("WPA2-EAP");
            break;
        case WIFI_AUTH_WPA3_PSK:
            Serial.print("WPA3");
            break;
        case WIFI_AUTH_WPA2_WPA3_PSK:
            Serial.print("WPA2+WPA3");
            break;
        case WIFI_AUTH_WAPI_PSK:
            Serial.print("WAPI");
            break;
        default:
            Serial.print("unknown");
        }
        Serial.println();
        delay(10);
    }*/
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

#endif