//
// Created by Serdar on 7.11.2024.
//

#include <chrono>
#include <thread>
#include <WiFi.h>
#include <esp_wifi_types.h>
#include "comms/wifi_manager.h"

#include <sstream>

#include "logger/serial_logger.h"
#include "wifi.h"
#include "helper/network.h"

std::unique_ptr<WiFiManager> WiFiManager::instance = nullptr;

WiFiManager::~WiFiManager() = default;

WiFiManager::WiFiManager(): currentWiFi()
{
    WiFiClass::mode(WIFI_STA);
    SerialLog.Info("WifiManager initialized.");
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
    if (WiFiClass::status() == WL_CONNECTED)
        return true;

    return connect(WIFI_SSID, WIFI_PASSWORD);
}

bool WiFiManager::connect(const std::string& ssid, const std::string& password)
{
    if (WiFiClass::status() == WL_CONNECTED)
        return true;

    WiFiClass::mode(WIFI_STA);
    WiFi.begin(ssid.c_str(), password.c_str());

    int attempts = WIFI_REPEAT_LIMIT;

    while(WiFiClass::status() != WL_CONNECTED)
    {
        if (--attempts == 0)
        {
            SerialLog.Warning("Wifi conn failed.");
            return false;
        }

        SerialLog.Info("Wifi conn..[%d]", WIFI_REPEAT_LIMIT - attempts);
        delay(WIFI_REPEAT_INTERVAL);
    }
    SerialLog.Info("Wifi connected.");

    updateWiFiInfo();
    return true;
}

void WiFiManager::disconnect()
{
    if (WiFiClass::status() == WL_CONNECTED)
        WiFi.disconnect();
}

WifiInfo WiFiManager::getInfo()
{
    return currentWiFi;
}

void WiFiManager::updateWiFiInfo()
{

    WiFi.config(
        Network::makeIP(WIFI_IP),
        Network::makeIP(WIFI_GATEWAY),
        Network::makeIP(WIFI_SUBNET));
    SerialLog.Info("WiFi configured.");

    currentWiFi.ssid = WiFi.SSID().c_str();
    currentWiFi.bssid = WiFi.macAddress().c_str();
    currentWiFi.channel = WiFi.channel();
    currentWiFi.rssi = WiFi.RSSI();
    currentWiFi.ip = WiFi.localIP().toString().c_str();
    //currentWiFi.encryption = WiFi.encryptionType;

    SerialLog.Info("SSID:%s", WiFi.SSID().c_str());
    SerialLog.Info("IP:%s", WiFi.localIP().toString().c_str());

    SerialLog.Info("Wifi updated.");
}


bool WiFiManager::getStatus()
{
    if(WiFiClass::status() == WL_CONNECTED)
        return true;
    return false;
}
