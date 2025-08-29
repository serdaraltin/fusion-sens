//
// Created by main on 29.08.2025.
//

#ifndef SENSOR_H
#define SENSOR_H

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


#endif //SENSOR_H
