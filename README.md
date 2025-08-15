# Fusion Sens

Fusion Sens is a versatile C++ software framework designed for working with I2C-based sensors on microcontroller platforms, such as the **ESP32**. It abstracts the complexities of managing multiple sensors and streamlines the process of interacting with I2C devices like **MPU6050**, **BMP180**, **SSD1306**, and more. The project is built with flexibility and extensibility in mind, enabling developers to manage sensor data, perform device configuration, and log sensor readings seamlessly.

## Table of Contents

1. [Features](#features)
2. [Architecture](#architecture)
3. [Getting Started](#getting-started)
4. [Installation](#installation)
5. [Configuration](#configuration)
6. [Usage](#usage)
    - [Device Class](#device-class)
    - [DeviceManager Class](#devicemanager-class)
    - [I2C Class](#i2c-class)
    - [Logger and SerialLogger Classes](#logger-and-seriallogger-classes)
    - [Adding a New Device](#adding-a-new-device)
    - [Unit Tests](#unit-tests)
7. [Contribution](#contribution)
8. [License](#license)
9. [API Reference](#api-reference)
10. [Changelog](#changelog)

## Features

- **Device Management:** Provides a `DeviceManager` class that manages a list of I2C devices and allows adding, retrieving, and removing devices dynamically.
- **I2C Communication:** A robust system for managing I2C bus communication, with features like automatic device scanning, connection checking, and communication retries.
- **Logging:** Includes a logging system with multiple verbosity levels (None, Error, Warning, Info, Debug), along with a `SerialLogger` for sending logs over the serial port for debugging.
- **Sensor Abstraction:** Abstracts sensor details such as addresses and properties, providing a simple interface for developers to interact with the sensors.
- **Unit Testing Support:** Integrated with Google Test for unit testing, ensuring that the framework is reliable and bug-free.

## Architecture

The Fusion Sens framework follows a modular and extensible architecture:

- **Device Class:** Represents individual I2C devices with properties like name, address, and parent device.
- **DeviceManager Class:** A singleton pattern manager for handling multiple devices. It stores, retrieves, and removes devices dynamically.
- **I2C Class:** Encapsulates the I2C bus operations, including initialization, scanning for connected devices, and communication with the devices.
- **Logger and SerialLogger Classes:** Used for logging various levels of information and sending those logs over a serial connection.

### Key Components:

- **Device**: Represents an individual device in the I2C bus. Each device has properties like name, address, and a reference to its parent device.
- **DeviceManager**: Handles a collection of devices. Provides an API to add, remove, or retrieve devices from the list.
- **I2C**: Manages the communication between the microcontroller and I2C sensors. Handles device scanning, addressing, and data exchange.
- **Logger**: Provides logging functionality, with options to log messages at different severity levels.

## Getting Started

Follow the instructions below to set up and start using the **Fusion Sens** framework.

### Prerequisites

1. **C++11 or later** compiler support
2. **ESP32 or another compatible microcontroller** (Alternatively, other platforms like ESP8266 are supported)
3. **CLion** or any other C++ IDE for development
4. **I2C-compatible sensors** like **MPU6050**, **BMP180**, **SSD1306** (These can be connected to the microcontroller using the I2C protocol)

### Supported Platforms

- **ESP32**
- **ESP8266**
- **Arduino (via PlatformIO)**

### Hardware Requirements

- **MPU6050** (Accelerometer, Gyroscope)
- **BMP180** (Barometer)
- **SSD1306** (OLED display)

You can add more I2C sensors by creating new `Device` objects or modifying the `DeviceManager` class.

### Installation

To get started, clone the project to your local machine using Git:

```bash
git clone https://github.com/serdaraltin/fusion-sens.git
```

After cloning, open the project in your preferred C++ IDE (**CLion** is recommended, but **Visual Studio Code** with PlatformIO is also supported).

```bash
cd fusion-sens
```

Install dependencies via **PlatformIO** (if using PlatformIO as the IDE):

```bash
platformio lib install
```

Alternatively, if using **Arduino IDE**, install the following libraries:

- **Wire** (for I2C communication)
- **Adafruit_SSD1306** (for OLED display support)
- **Adafruit_GFX** (for graphics rendering on displays)

### Dependencies

The project requires the following libraries to work:

- **Wire**: Standard library for I2C communication.
- **Adafruit_SSD1306**: Used for controlling OLED displays over I2C.
- **Adafruit_GFX**: Provides graphics functions for the OLED display.
- **Google Test**: For unit testing (optional).

These dependencies can be installed through the PlatformIO IDE or Arduino IDE.

## Configuration

The configuration files are located in the `config` folder. These files are designed to make it easy to configure the microcontroller and sensors.

### Example Configuration File (`config/config.h`)

```cpp
// I2C Configuration
#define SDA_PIN 21
#define SCL_PIN 22

// Screen Configuration
#define SCREEN_I2C 0x3C

// Sensor Configuration
#define SENSOR_NAME "MPU6050"
#define SENSOR_I2C 0x68
```

In the above configuration:

- **SDA_PIN** and **SCL_PIN** define the I2C data and clock pins.
- **SCREEN_I2C** specifies the I2C address of the OLED screen.
- **SENSOR_I2C** defines the I2C address of the sensor (MPU6050 in this case).

### Customizing the Device List

You can modify the device list by editing the `DeviceManager` class or directly using the `addDevice()` method to add devices dynamically.

## Usage

### Device Class

The `Device` class represents an I2C device and provides methods for interacting with it.

#### Example Usage:

```cpp
DeviceManagerI.addDevice({"NewDevice", 0xAB});
Device *device = DeviceManagerI.getDevice(0xAB);
```

### DeviceManager Class

The `DeviceManager` class manages all devices. It allows you to add, remove, and retrieve devices from a list.

#### Example Usage:

```cpp
// Add a device to the manager
DeviceManagerI.addDevice({"NewDevice", 0xAB});

// Retrieve a device from the manager
Device *device = DeviceManagerI.getDevice(0xAB);
```

### I2C Class

The `I2C` class encapsulates I2C communication functions.

#### Example Usage:

```cpp
I2CI.wireBegin();  // Start the I2C bus
I2CI.scan();       // Scan the I2C bus for connected devices
```

### Logger and SerialLogger Classes

The `Logger` class logs messages at different levels of severity. The `SerialLogger` extends this class and sends logs over a serial connection.

#### Example Usage:

```cpp
ISerialLog.Info("Device initialized.");
ISerialLog.Debug("I2C device communication successful.");
```

### Adding a New Device

To add a new device, create an instance of the `Device` class and add it to the `DeviceManager`.

#### Example:

```cpp
Device newDevice("NewDevice", 0xAB);
DeviceManagerI.addDevice(newDevice);
```

### Unit Tests

Unit tests are implemented using **Google Test**. To run the tests, you can execute the following command using PlatformIO:

```bash
pio test -e esp32-Test
```

The tests will ensure that the framework works as expected and that all components are functioning correctly.

## Contribution

Contributions are welcome! Please feel free to fork the repository, make your changes, and submit a pull request. Here's how you can contribute:

1. Fork the repository
2. Create a new branch
3. Make your changes and test them
4. Submit a pull request with a detailed description of your changes

## License

This project is licensed under the **GPL-3.0 License**. See the [LICENSE](LICENSE) file for more information.

## API Reference

### Device Class

- **`Device(String name, uint8_t address, uint8_t parentAddress = 0)`**: Constructor that creates a device with the given name, address, and optional parent address.
- **`String getName()`**: Returns the name of the device.
- **`uint8_t getAddress()`**: Returns the I2C address of the device.
- **`uint8_t getParentDevice()`**: Returns the I2C address of the parent device (if any).

### DeviceManager Class

- **`void addDevice(Device device)`**: Adds a device to the manager.
- **`Device* getDevice(uint8_t address)`**: Retrieves a device by its I2C address.

### I2C Class

- **`void wireBegin()`**: Initializes the I2C communication.
- **`void scan()`**:

Scans the I2C bus for connected devices.

### Logger Class

- **`void Info(String message)`**: Logs an informational message.
- **`void Error(String message)`**: Logs an error message.
- **`void Debug(String message)`**: Logs a debug message.