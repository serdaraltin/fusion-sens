//
// Created by Serdar on 7.11.2024.
//

#include "comms/wifi_manager.h"
#include "wifi.h"
#include <WiFi.h>
#include <logger/serial_logger.h>

WiFiManager* WiFiManager::instance = nullptr;

WiFiManager::~WiFiManager() = default;

WiFiManager::WiFiManager()
{
    WiFi.mode(WIFI_STA);
    SerialLog.Info("WifiManager initialized");
}

std::vector <WiFiInfo> WiFiManager::scanNetworks() {


    return std::vector<WiFiInfo>();
}

bool WiFiManager::connectToNetwork()
{
    return connectToNetwork(WIFI_SSID, WIFI_PASSWORD);
}

bool WiFiManager::connectToNetwork(const std::string &ssid, const std::string &password) {
    WiFi.begin(ssid.c_str(),password.c_str());
    int i=WIFI_REPEAT_LIMIT;
    while (WiFi.status() != WL_CONNECTED)
    {
        if(i==0)
            return false;
        SerialLog.Info("WiFi conn...[%d]",WIFI_REPEAT_LIMIT-i);
        delay(WIFI_REPEAT_INTERVAL);
        i--;
    }
    SerialLog.Info("WiFi connected");
    return true;
}

WiFiInfo WiFiManager::getCurrentNetworkInfo() {
    return WiFiInfo();
}

std::string WiFiManager::getIpAddress()
{
    return std::string();
}


