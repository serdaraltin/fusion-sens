//
// Created by Serdar on 7.11.2024.
//

#ifndef FUSION_SENS_WIFI_MANAGER_H
#define FUSION_SENS_WIFI_MANAGER_H

#include <esp_wifi_types.h>
#include <string>
#include <utility>
#include <vector>
#include <memory>
#include <mutex>
#include <sstream>
#include <helper/network.h>

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
    int channel = -1;                   ///< Channel number
    int8_t rssi = 0;                   ///< Signal strength in dBm
    wifi_auth_mode_t encryption = WIFI_AUTH_OPEN;   ///< Encryption type (WPA2, WPA3, etc.)

  WifiInfo() = default;

  WifiInfo(std::string  ssid,
           std::string  password,
           std::string  bssid,
           std::string  ip,
           const int channel,
           const int8_t rssi,
           const wifi_auth_mode_t encryption
  ):ssid(std::move(ssid)),
    password(std::move(password)),
    bssid(std::move(bssid)),
    ip(std::move(ip)),
    channel(channel),
    rssi(rssi),
    encryption(encryption){}

 WifiInfo(std::string  ssid,
          const int channel,
          const int8_t rssi,
          const wifi_auth_mode_t encryption
 ):ssid(std::move(ssid)),
   channel(channel),
   rssi(rssi),
   encryption(encryption){}

 WifiInfo(std::string  ssid,
          std::string  password
 ): ssid(std::move(ssid)),
    password(std::move(password)), channel(0), rssi(0), encryption()
    {
    }

 std::string to_string() const
  {
   std::ostringstream os;
   os << "SSID: " << ssid << "\n"
      << "RSSI: " << static_cast<int>(rssi) << " dBm\n"
      << "Encryption: " << Network::wifiAuthModeToString(encryption) << "\n";
   return os.str();
  }

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
