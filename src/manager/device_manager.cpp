//
// Created by Serdar on 6.11.2024.
//

#include "manager/device_manager.h"
#include "device_list.h"
#include "helper/hex.h"
#include <algorithm>

DeviceManager *DeviceManager::instance = nullptr;

DeviceManager *DeviceManager::getInstance() {
    if(instance == nullptr)
        instance = new DeviceManager();
    return instance;
}

DeviceManager::DeviceManager() {
    deviceList = sDeviceList;
}

DeviceManager::DeviceManager(const std::vector<Device> &deviceList)
: deviceList(deviceList) {}

const std::vector<Device> &DeviceManager::getDeviceList() const {
    return deviceList;
}

void DeviceManager::setDeviceList(const std::vector<Device> &_deviceList) {
    DeviceManager::deviceList = _deviceList;
}

bool DeviceManager::addDevice(const Device& _device) {
    if(checkDevice(_device.getAddress()))
        return false;
    deviceList.emplace_back(_device);
    return true;
}

Device *DeviceManager::getDevice(const uint8_t _address) {
    for(Device &device: deviceList){
        if(device.getAddress() == _address){
            return &device;
        }
    }
    return nullptr;
}

bool DeviceManager::checkDevice(uint8_t _deviceAddress) {

    auto it = std::find_if(deviceList.begin(), deviceList.end(), [_deviceAddress](const Device& device){
        return device.getAddress() == _deviceAddress;
    });
    if(it != deviceList.end())
        return true;
    return false;
}

bool DeviceManager::removeDevice(uint8_t deviceAddress) {
    auto it = std::remove_if(deviceList.begin(), deviceList.end(),
                             [deviceAddress] (const Device& device){
                                 return device.getAddress() == deviceAddress;
                             });
    if(it == deviceList.end())
        return false;
    deviceList.erase(it, deviceList.end());
    return true;
}






