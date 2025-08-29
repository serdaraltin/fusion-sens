//
// Created by Serdar on 7.11.2024.
//

#ifndef FUSION_SENS_WIFI_MANAGER_H
#define FUSION_SENS_WIFI_MANAGER_H

#include <esp_wifi_types.h>
#include <string>
#include <vector>
#include <optional>
#include <functional>
#include <memory>

#define IWiFi WiFiManager::getInstance()

struct WifiInfo
{
    std::string ssid;
    std::string password;
    std::string bssid;
    int32_t rssi;
    int32_t channel;
    wifi_auth_mode_t encryption;
    std::string ip;
};

class WiFiManager{
private:
    static std::unique_ptr<WiFiManager> instance;
    WifiInfo currentWiFi;

    WiFiManager();

public:

    ~WiFiManager();

    static WiFiManager& getInstance();

    std::vector<WifiInfo> scanNetworks();

    bool connect();

    bool connect(const std::string& ssid, const std::string& password);

    void disconnect();

    WifiInfo getInfo();

    static wl_status_t getStatus();

};



#endif // FUSION_SENS_WIFI_MANAGER_H
