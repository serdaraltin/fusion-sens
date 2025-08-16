/**
 * @file device_manager_test.cpp
 * @brief Unit tests for the DeviceManager class using Google Test Framework.
 *
 * This file contains tests for the DeviceManager class, which is responsible
 * for managing a collection of Device objects. The tests verify functionalities
 * such as adding devices, removing devices, retrieving devices by address,
 * and ensuring the singleton behavior.
 *
 * @author Serdar
 * @date 19.11.2024
 */

#include <gtest/gtest.h>
#include "device/device.h"
#include "manager/device_manager.h"

/**
 * @class DeviceManagerTest
 * @brief Test fixture for testing DeviceManager.
 *
 * This class provides a test fixture to set up and tear down the state
 * of the DeviceManager for each test case. It ensures that the device
 * list is reset to an empty state before each test.
 */
class DeviceManagerTest : public ::testing::Test {
protected:
    /**
     * @brief Sets up the test environment before each test case.
     *
     * This method clears the device list in the singleton DeviceManager instance
     * to ensure a clean state for each test.
     */
    void SetUp() override {
        DeviceManager().getInstance()->setDeviceList({});
    }

    /**
     * @brief Cleans up the test environment after each test case.
     *
     * This method is called automatically after each test. Currently,
     * it does not perform any specific operations.
     */
    void TearDown() override {}
};

/**
 * @test SingletonInstance
 * @brief Verifies that DeviceManager follows the singleton pattern.
 */
TEST_F(DeviceManagerTest, SingletonInstance) {
    DeviceManager *manager1 = DeviceManager::getInstance();
    DeviceManager *manager2 = DeviceManager::getInstance();
    ASSERT_EQ(manager1, manager2);
}

/**
 * @test AddDevice
 * @brief Verifies that a device can be successfully added to the device list.
 */
TEST_F(DeviceManagerTest, AddDevice) {
    Device device("MPU6050", 0x68);
    bool success = DeviceManager::getInstance()->addDevice(device);
    ASSERT_TRUE(success);

    Device *retrievedDevice = DeviceManager::getInstance()->getDevice(0x68);
    ASSERT_NE(retrievedDevice, nullptr);
    ASSERT_EQ(retrievedDevice->getName(), "MPU6050");
    ASSERT_EQ(retrievedDevice->getAddress(), 0x68);
}

/**
 * @test AddDuplicateDevice
 * @brief Ensures that adding a duplicate device (same address) fails.
 */
TEST_F(DeviceManagerTest, AddDuplicateDevice) {
    Device device1("MPU6050", 0x68);
    Device device2("MPU6050", 0x68);
    ASSERT_TRUE(DeviceManager::getInstance()->addDevice(device1));
    ASSERT_FALSE(DeviceManager::getInstance()->addDevice(device2));
}

/**
 * @test GetDeviceByAddress
 * @brief Verifies that a device can be retrieved by its I2C address.
 */
TEST_F(DeviceManagerTest, GetDeviceByAddress) {
    Device device("MPU6050", 0x68);
    DeviceManager::getInstance()->addDevice(device);

    Device *retrievedDevice = DeviceManager::getInstance()->getDevice(0x68);
    ASSERT_NE(retrievedDevice, nullptr);
    ASSERT_EQ(retrievedDevice->getName(), "MPU6050");
    ASSERT_EQ(retrievedDevice->getAddress(), 0x68);
}

/**
 * @test GetDeviceByNonExistentAddress
 * @brief Ensures that attempting to retrieve a device with a nonexistent address returns nullptr.
 */
TEST_F(DeviceManagerTest, GetDeviceByNonExistentAddress) {
    Device *retrievedDevice = DeviceManager::getInstance()->getDevice(0x99);
    ASSERT_EQ(retrievedDevice, nullptr);
}

/**
 * @test RemoveDevice
 * @brief Tests the ability to remove a device from the device list.
 */
TEST_F(DeviceManagerTest, RemoveDevice) {
    Device device("MPU6050", 0x68);
    DeviceManager::getInstance()->addDevice(device);

    bool removeSuccess = DeviceManager::getInstance()->removeDevice(device.getAddress());
    ASSERT_TRUE(removeSuccess);

    Device *retrievedDevice = DeviceManager::getInstance()->getDevice(0x68);
    ASSERT_EQ(retrievedDevice, nullptr);
}

/**
 * @test RemoveNonExistentDevice
 * @brief Verifies that attempting to remove a nonexistent device returns false.
 */
TEST_F(DeviceManagerTest, RemoveNonExistentDevice) {
    bool removeSuccess = DeviceManager::getInstance()->removeDevice(0x99);
    ASSERT_FALSE(removeSuccess);
}

/**
 * @test SetDeviceList
 * @brief Tests setting a new list of devices for the DeviceManager.
 */
TEST_F(DeviceManagerTest, SetDeviceList) {
    Device device1("MPU6050", 0x68);
    Device device2("BMP180", 0x77);
    std::vector<Device> newDeviceList = {device1, device2};

    DeviceManager::getInstance()->setDeviceList(newDeviceList);

    const std::vector<Device> &deviceList = DeviceManager::getInstance()->getDeviceList();
    ASSERT_EQ((int)deviceList.size(), 2);
    ASSERT_EQ(deviceList[0].getAddress(), 0x68);
    ASSERT_EQ(deviceList[1].getAddress(), 0x77);
}

/**
 * @test InitialEmptyDeviceList
 * @brief Ensures that the device list is initially empty.
 */
TEST_F(DeviceManagerTest, InitialEmptyDeviceList) {
    const std::vector<Device> &deviceList = DeviceManager::getInstance()->getDeviceList();
    ASSERT_TRUE(deviceList.empty());
}

/**
 * @test CheckDevice
 * @brief Tests the `checkDevice` method to verify a device's existence.
 */
TEST_F(DeviceManagerTest, CheckDevice) {
    Device device("MPU6050", 0x68);
    DeviceManager::getInstance()->addDevice(device);

    bool checkSuccess = DeviceManager::getInstance()->checkDevice(device.getAddress());
    ASSERT_TRUE(checkSuccess);

    DeviceManager::getInstance()->removeDevice(device.getAddress());
    checkSuccess = DeviceManager::getInstance()->checkDevice(device.getAddress());
    ASSERT_FALSE(checkSuccess);
}
