//
// Created by Serdar on 5.11.2024.
//

#ifndef FUSION_SENS_SERIAL_LOGGER_H
#define FUSION_SENS_SERIAL_LOGGER_H

#include "logger.h"

#define SerialLog SerialLogger::getInstance()->Log

/**
 * @file serial_logger.h
 * @brief A subclass of Logger that logs messages to the serial port.
 *
 * This class extends the `Logger` class to provide logging functionality specifically for
 * outputting log messages to a serial port. It overrides the `log2String` method to implement
 * serial-specific behavior. The Singleton design pattern is used to ensure only one instance
 * of the `SerialLogger` exists throughout the application.
 *
 * Example usage:
 * ```cpp
 * SerialLogger::getInstance()->setLevel(Logger::Info);
 * SerialLogger::getInstance()->Log.Info("Serial log message");
 * ```
 */
class SerialLogger : public Logger {
private:
    static SerialLogger *instance; ///< Static instance of SerialLogger for Singleton pattern

public:
    /**
     * @brief Constructor for the SerialLogger class.
     *
     * Initializes the serial connection and prepares the logger for logging.
     */
    SerialLogger();

    /**
     * @brief Deleted copy constructor to prevent copying.
     *
     * Prevents copying of the Singleton instance.
     */
    SerialLogger(const SerialLogger &) = delete;

    /**
     * @brief Default destructor for SerialLogger.
     *
     * Cleans up the SerialLogger instance when it is destroyed.
     */
    ~SerialLogger() override = default;

    /**
     * @brief Deleted copy assignment operator to prevent assignment.
     *
     * Prevents assignment of the Singleton instance.
     */
    SerialLogger &operator=(const SerialLogger &) = delete;

    /**
     * @brief Retrieves the Singleton instance of SerialLogger.
     * @return A pointer to the static instance of SerialLogger.
     *
     * This method ensures that only one instance of SerialLogger exists in the application.
     */
    static SerialLogger *getInstance();

    /**
     * @brief Converts the log message to a string for serial output.
     * @param level The level of the log message (e.g., Error, Info).
     * @param message The message to be logged.
     * @return An optional string containing the formatted log message.
     *
     * This method overrides the `log2String` method from the `Logger` class.
     * It formats the log message and prepares it for serial output.
     */
    std::string log2String(Level level, const std::string &message) override;

};

#endif //FUSION_SENS_SERIAL_LOGGER_H
