//
// Created by Serdar on 7.11.2024.
//

#include "comms/wifi_manager.h"
#include "wifi.h"
#include <WiFi.h>
#include <logger/serial_logger.h>

WiFiManager* WiFiManager::instance = nullptr;
WiFiInfo WiFiManager::currentNetworkInfo;

WiFiManager::~WiFiManager() = default;

WiFiManager::WiFiManager()
{
    WiFi.mode(WIFI_STA);
    SerialLog.Info("WifiManager initialized");
}

std::vector <WiFiInfo> WiFiManager::scanNetworks() {
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);

    int networks = WiFi.scanNetworks();
    for (int i = 0; i < networks; i++)
    {

    }

    return std::vector<WiFiInfo>();
}

bool WiFiManager::connectToNetwork()
{
    return connectToNetwork(WIFI_SSID, WIFI_PASSWORD);
}

bool WiFiManager::connectToNetwork(const std::string &ssid, const std::string &password) {
    WiFi.begin(ssid.c_str(),password.c_str());

    int attempts = WIFI_REPEAT_LIMIT;
    while (WiFi.status() != WL_CONNECTED)
    {
        if(attempts==0)
            return false;
        SerialLog.Info("WiFi conn...[%d]",WIFI_REPEAT_LIMIT - attempts);
        delay(WIFI_REPEAT_INTERVAL);
        attempts--;
    }

    currentNetworkInfo.ssid = WiFi.SSID().c_str();
    currentNetworkInfo.bssid = WiFi.BSSIDstr().c_str();
    currentNetworkInfo.rssi = WiFi.RSSI();
    currentNetworkInfo.channel = WiFi.channel();
    currentNetworkInfo.ip = WiFi.macAddress().c_str();
    currentNetworkInfo.mac = WiFi.macAddress().c_str();
    //currentNetworkInfo->encryption = (WiFi.encryptionType() == WIFI_AUTH_OPEN) ? "Open" : "Encrypted";

    SerialLog.Info("WiFi connected");
    return true;
}

WiFiInfo WiFiManager::getCurrentNetworkInfo() {
    return currentNetworkInfo;
}

std::string WiFiManager::getIpAddress()
{
    return currentNetworkInfo.ip;
}


