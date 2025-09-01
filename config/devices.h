//
// Created by Serdar on 6.11.2024.
//

#ifndef FUSION_SENS_DEVICE_LIST_H
#define FUSION_SENS_DEVICE_LIST_H

#include <vector>
#include <string>
#include "device/device.h"

/**
 * @file device_list.h
 * @brief A header file that contains a static list of predefined devices.
 *
 * This file defines a static list `sDeviceList` that contains a set of predefined devices,
 * each initialized with a name, address, and optionally a parent device address.
 * This list can be used to access and manage devices within the system.
 *
 * ### How to Add a Device
 *
 * To add a new device to the list, you can directly append a new `Device` instance
 * with the required parameters (name, address, and optionally parent device address) to the
 * `sDeviceList` vector.
 *
 * Example:
 * ```cpp
 * sDeviceList.push_back({"NewDevice", 0xAB});
 * ```
 * This will add the new device to the list with the specified address.
 * Ensure that the device name and address do not conflict with any existing devices.
 */
static std::vector<Device> sDeviceList = {
        {"MPU6050", 0x68},         ///< MPU6050 device with address 0x68
        {"BMP180", 0x77, 0x68},    ///< BMP180 device with address 0x77, parent address 0x68
        {"SSD1306", 0x3C}          ///< SSD1306 device with address 0x3C

        // To add a new device, simply use the following format:
        // {"NewDevice", 0xAB},      ///< NewDevice with address 0xAB
        // If the device has a parent, specify its address as the third argument:
        // {"NewDeviceWithParent", 0xCD, 0xAB}   ///< NewDeviceWithParent with address 0xCD, parent address 0xAB
};

#endif //FUSION_SENS_DEVICE_LIST_H
