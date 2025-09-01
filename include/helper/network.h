//
// Created by main on 29.08.2025.
//

#ifndef NETWORK_H
#define NETWORK_H

#include <WiFi.h>
#include <string>


class Network {
 public:
    Network() = delete;
    ~Network() = delete;

    static IPAddress makeIP(const char *ipString);

    static IPAddress makeIP(uint8_t a, uint8_t b, uint8_t c, uint8_t d);

    static IPAddress broadcastAddress(const IPAddress &ip, const IPAddress &subnet);

    static bool inSameSubnet(const IPAddress &a, const IPAddress &b, const IPAddress subnet);

    static std::string ipToString(const IPAddress &ip);

    static bool ping(const IPAddress &ip);

    static std::string wifiAuthModeToString(wifi_auth_mode_t mode);
};



#endif //NETWORK_H
