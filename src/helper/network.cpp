//
// Created by main on 29.08.2025.
//

#include "helper/network.h"

IPAddress Network::makeIP(const char* ipString)
{
    IPAddress ip;
    ip.fromString(ipString);
    return ip;
}

IPAddress Network::makeIP(uint8_t a, uint8_t b, uint8_t c, uint8_t d)
{
    return IPAddress(a, b, c, d);
}

IPAddress Network::broadcastAddress(const IPAddress& ip, const IPAddress& subnet)
{
    IPAddress broadcast;
    for(int i=0;i<4; ++i)
    {
        broadcast[i] = ip[i] | (~subnet[i]);
    }
    return broadcast;
}

bool Network::inSameSubnet(const IPAddress& a, const IPAddress& b, const IPAddress subnet)
{
    for(int i=0;i<4;++i)
    {
        if((a[i] & subnet[i]) != (b[i] & subnet[i]))
            return false;
    }
    return true;
}

std::string Network::ipToString(const IPAddress& ip)
{
    char buffer[16];
    sprintf(buffer, "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
    return std::string(buffer);
}

bool Network::ping(const IPAddress& ip)
{
    //TODO: ICMP ping veya WiFiUDP tabanlı ping implementasyonu
    return true;
}

std::string Network::wifiAuthModeToString(wifi_auth_mode_t mode)
{
    switch (mode)
    {
    case WIFI_AUTH_OPEN:           return "Open";
    case WIFI_AUTH_WEP:            return "WEP";
    case WIFI_AUTH_WPA_PSK:        return "WPA_PSK";
    case WIFI_AUTH_WPA2_PSK:       return "WPA2_PSK";
    case WIFI_AUTH_WPA_WPA2_PSK:   return "WPA_WPA2_PSK";
    case WIFI_AUTH_ENTERPRISE:     return "Enterprise (EAP)";
    case WIFI_AUTH_WPA3_PSK:       return "WPA3_PSK";
    case WIFI_AUTH_WPA2_WPA3_PSK:  return "WPA2_WPA3_PSK";
    case WIFI_AUTH_WAPI_PSK:       return "WAPI_PSK";
    case WIFI_AUTH_WPA3_ENT_192:   return "WPA3_ENT_SUITE_B_192";
    case WIFI_AUTH_MAX:            return "Invalid/Max";
    default:                       return "Unknown";
    }
}