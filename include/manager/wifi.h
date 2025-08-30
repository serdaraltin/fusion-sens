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

/// Shortcut macro for accessing WiFiManager singleton instance
#define IWiFi WiFiManager::getInstance()

/**
 * @struct WifiInfo
 * @brief Stores information about a WiFi network and current connection.
 */
struct WifiInfo
{
    std::string ssid;              ///< SSID of the network
    std::string password;          ///< Password (only for stored credentials)
    std::string bssid;             ///< BSSID (MAC address of AP)
    std::string ip;                ///< Local IP when connected
    int channel;                   ///< Channel number
    int8_t rssi;                   ///< Signal strength in dBm
    wifi_auth_mode_t encryption;   ///< Encryption type (WPA2, WPA3, etc.)
};

/**
 * @class WiFiManager
 * @brief Singleton class that wraps ESP-IDF WiFi functions for simplified use.
 *
 * Provides scanning, connecting, disconnecting and retrieving network info.
 */
class WiFiManager {
private:
    static std::unique_ptr<WiFiManager> instance; ///< Singleton instance
    WifiInfo currentWiFi;                         ///< Currently connected WiFi info

    /// Private constructor for singleton
    WiFiManager();

    /// Updates currentWiFi with active connection details
    void updateWiFiInfo();

public:

    /// Destructor
    ~WiFiManager();

    /**
     * @brief Get the singleton instance of WiFiManager
     * @return Reference to WiFiManager instance
     */
    static WiFiManager& getInstance();

    /**
     * @brief Scan for available WiFi networks
     * @return Vector of WifiInfo objects containing SSID, RSSI, encryption, etc.
     */
    static std::vector<WifiInfo> scanNetworks();

    /**
     * @brief Connect using stored credentials in currentWiFi
     * @return true if connection successful, false otherwise
     */
    bool connect();

    /**
     * @brief Connect to WiFi with SSID and Password
     * @param ssid SSID of the target WiFi
     * @param password Password of the target WiFi
     * @return true if connected successfully, false otherwise
     */
    bool connect(const std::string& ssid, const std::string& password);

    /**
     * @brief Disconnect from the current WiFi
     */
    static void disconnect();

    /**
     * @brief Get current WiFi information
     * @return WifiInfo struct with SSID, BSSID, IP, RSSI, etc.
     */
    WifiInfo getInfo();

    /**
     * @brief Get current WiFi connection status
     * @return true if connected, false otherwise
     */
    static bool getStatus();
};

#endif // FUSION_SENS_WIFI_MANAGER_H
