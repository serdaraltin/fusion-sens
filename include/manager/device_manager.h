//
// Created by Serdar on 6.11.2024.
//

#ifndef FUSION_SENS_DEVICE_MANAGER_H
#define FUSION_SENS_DEVICE_MANAGER_H

#include "device/device.h"
#include "config/device_list.h"
#include <vector>

/**
 * @file device_manager.h
 * @brief Singleton class to manage a list of devices.
 *
 * This class manages a collection of `Device` objects and provides an interface to:
 * - Add a new device
 * - Get a list of all devices
 * - Retrieve a device by its address
 *
 * The class ensures only one instance of the manager exists using the Singleton design pattern.
 * The device list can be accessed or modified using its public methods.
 *
 * Example usage:
 * ```cpp
 * DeviceManager *manager = DeviceManager::getInstance();
 * manager->addDevice(Device("MPU6050", 0x68));
 * ```
 */
#define DeviceManagerI DeviceManager::getInstance()

class DeviceManager {
private:
    static DeviceManager *instance; ///< The static instance of the singleton
    std::vector<Device> deviceList; ///< A list of `Device` objects
public:
    /**
     * @brief Default constructor that initializes an empty device list.
     *
     * This constructor creates an empty list of devices, ready to be populated.
     */
    DeviceManager();

    /**
     * @brief Destructor for the DeviceManager class.
     *
     * The destructor is default and does not perform additional operations.
     */
    ~DeviceManager() = default;

    /**
     * @brief Constructor that initializes the device manager with a given list of devices.
     * @param deviceList A vector of `Device` objects to initialize the manager with.
     */
    explicit DeviceManager(const std::vector<Device> &deviceList);

    /**
     * @brief Retrieves the singleton instance of the DeviceManager class.
     * @return A pointer to the static instance of DeviceManager.
     *
     * This method ensures that only one instance of DeviceManager is used in the application.
     */
    static DeviceManager *getInstance();

    /**
     * @brief Retrieves the list of devices managed by this manager.
     * @return A constant reference to the vector of `Device` objects.
     */
    [[nodiscard]] const std::vector<Device> &getDeviceList() const;

    /**
     * @brief Sets a new list of devices for the manager.
     * @param deviceList A vector of `Device` objects to set as the new device list.
     */
    void setDeviceList(const std::vector<Device> &deviceList);

    /**
     * @brief Adds a new device to the device list.
     * @param device A `Device` object to be added to the list.
     * @return True if the device was successfully added, false otherwise.
     */
    bool addDevice(const Device& device);

    /**
     * @brief Retrieves a device by its I2C address.
     * @param address The I2C address of the device to retrieve.
     * @return A pointer to the `Device` object with the specified address, or nullptr if no device is found.
     */
    Device *getDevice(const uint8_t address);

    bool checkDevice(uint8_t deviceAddress);

    bool removeDevice(uint8_t deviceAddress);
};

#endif //FUSION_SENS_DEVICE_MANAGER_H
