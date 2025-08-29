//
// Created by main on 29.08.2025.
//

#ifndef COMM_H
#define COMM_H

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



#endif //COMM_H
