//
// Created by Serdar on 7.11.2024.
//

#ifndef FUSION_SENS_WIFI_MANAGER_H
#define FUSION_SENS_WIFI_MANAGER_H

#include <string>
#include <vector>
#include <optional>

#define IWiFi WiFiManager::getInstance()

struct WiFiInfo {
    std::string ssid;       ///< SSID of the network
    std::string bssid;      ///< BSSID (MAC address) of the network
    int rssi;               ///< Signal strength (RSSI)
    int channel;            ///< Channel number
    std::string ip;
    std::string mac;
    std::string encryption; ///< Encryption type
};

class WiFiManager{
private:
    static WiFiManager *instance;
    static WiFiInfo currentNetworkInfo;

    std::vector<WiFiInfo> scannedNetworks;

    WiFiManager();

public:

    ~WiFiManager();

    static WiFiManager &getInstance()
    {
        static WiFiManager instance;
        return instance;
    }

    static std::vector<WiFiInfo> scanNetworks();

    static bool connectToNetwork();

    static bool connectToNetwork(const std::string &ssid, const std::string &password);

    static WiFiInfo getCurrentNetworkInfo() ;

    static std::string getIpAddress();

};



#endif // FUSION_SENS_WIFI_MANAGER_H
