//
// Created by Serdar on 7.11.2024.
//

#include <chrono>
#include <thread>
#include <WiFi.h>

#include "comms/wifi_manager.h"
#include <logger/serial_logger.h>
#include "config_wifi.h"

std::unique_ptr<WiFiManager> WiFiManager::instance = nullptr;

WiFiManager::~WiFiManager() = default;

WiFiManager::WiFiManager()
{
    WiFi.mode(WIFI_STA);
    SerialLog.Info("WifiManager initialized");
}

WiFiManager& WiFiManager::getInstance()
{
    if (!instance)
        instance.reset(new WiFiManager());
    return *instance;
}

std::vector<WifiInfo> WiFiManager::scanNetworks()
{
    std::vector<WifiInfo> networks;

    return networks;
}

bool WiFiManager::connect()
{
    if (WiFi.status() == WL_CONNECTED)
        return true;

    return connect(WIFI_SSID, WIFI_PASSWORD);
}

bool WiFiManager::connect(const std::string& ssid, const std::string& password)
{
    if (WiFi.status() == WL_CONNECTED)
        return true;

}

void WiFiManager::disconnect()
{
    if (WiFi.status() == WL_CONNECTED)
        WiFi.disconnect();
}

WifiInfo WiFiManager::getInfo()
{
    return currentWiFi;
}

wl_status_t WiFiManager::getStatus()
{
    return WiFi.status();
}
