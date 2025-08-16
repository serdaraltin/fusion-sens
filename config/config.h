//
// Created by Serdar on 5.11.2024.
//

#ifndef FUSION_SENS_CONFIG_H
#define FUSION_SENS_CONFIG_H

/**
 * @file config.h
 * @brief Configuration file for the Fusion Sens project.
 *
 * This file contains all the necessary configuration settings for the Fusion Sens application.
 * It includes settings for serial communication, I2C configuration, SCREEN setup, and sensor initialization.
 * These settings can be customized according to the hardware and requirements of the project.
 */

/**
 * @def APP_NAME
 * @brief The name of the application.
 *
 * This defines the application name for the Fusion Sens project.
 */
#define APP_NAME "Fusion Sens"

/**
 * @def LOG_LEVEL
 * @brief Log level for the application.
 *
 * This defines the log level for the application. In this case, it is set to "Info".
 */
#define LOG_LEVEL Debug

// Serial Configuration ============================================

/**
 * @def BOUD_RATE
 * @brief Baud rate for serial communication.
 *
 * This defines the baud rate for the serial communication, set to 115200.
 */
#define BOUD_RATE 115200

// I2C Configuration ============================================

/**
 * @def I2C_AUTO_BEGIN
 * @brief Whether to automatically initialize I2C.
 *
 * This defines whether the I2C bus should be automatically initialized at the start.
 */
#define I2C_AUTO_BEGIN true

/**
 * @def SDA_PIN
 * @brief The SDA pin for I2C communication.
 *
 * This defines the pin used for SDA (Serial Data) communication in I2C, set to pin 4.
 */
#define SDA_PIN 21

/**
 * @def SCL_PIN
 * @brief The SCL pin for I2C communication.
 *
 * This defines the pin used for SCL (Serial Clock) communication in I2C, set to pin 5.
 */
#define SCL_PIN 22




// SCREEN Configuration ============================================

/**
 * @def SCREEN_I2C
 * @brief The I2C address of the SCREEN screen.
 *
 * This defines the I2C address for the SCREEN screen, set to 0x3C.
 */
#define SCREEN_I2C 0x3C

/**
 * @def OLED_RESET
 * @brief The reset pin for the OLED screen.
 *
 * This defines the reset pin for the OLED screen, set to -1 if no reset pin is needed.
 */
#define OLED_RESET (-1)

/**
 * @def SCREEN_WIDTH
 * @brief The width of the SCREEN screen.
 *
 * This defines the width of the OLED screen in pixels, set to 128.
 */
#define SCREEN_WIDTH 128

/**
 * @def SCREEN_HEIGHT
 * @brief The height of the SCREEN screen.
 *
 * This defines the height of the OLED screen in pixels, set to 64.
 */
#define SCREEN_HEIGHT 64

#define SCREEN_LINE_LIMIT 8
#define SCREEN_CHARACTER_LIMIT 20

/**
 * @def BOOT_LOGO
 * @brief Whether to display the boot logo.
 *
 * This defines whether to display the boot logo on the screen during startup. Set to `true` to enable.
 */
#define BOOT_LOGO true

// Sensor Configuration ============================================

/**
 * @def SENSOR_NAME
 * @brief The name of the sensor.
 *
 * This defines the name of the sensor being used, set to "MPU6050".
 */
#define SENSOR_NAME "MPU6050"

/**
 * @def SENSOR_I2C
 * @brief The I2C address of the sensor.
 *
 * This defines the I2C address of the sensor, set to 0x68 for the MPU6050.
 */
#define SENSOR_I2C 0x68

/**
 * @def FIND_REPEAT
 * @brief Whether to repeatedly search for the sensor.
 *
 * This defines whether to search for the sensor repeatedly. Set to `true` to enable repeating the search.
 */
#define FIND_REPEAT true

#endif //FUSION_SENS_CONFIG_H
