//
// Created by Serdar on 5.11.2024.
//

#ifndef FUSION_SENS_LOGGER_H
#define FUSION_SENS_LOGGER_H

#include <string>
#include <optional>

/**
 * @file logger.h
 * @brief A logger class that provides various logging levels.
 *
 * This class is used for logging messages at different levels (None, Error, Warning, Info, Debug).
 * It uses the Singleton pattern to ensure only one instance of the logger exists throughout the application.
 * The logger supports dynamic log level setting and formatting of log messages with variable arguments.
 *
 * Example usage:
 * ```cpp
 * Logger::getInstance()->setLevel(Logger::Info);
 * Logger::getInstance()->Log.Info("This is an info message");
 * ```
 */
class Logger {
private:
    static Logger *instance; ///< Static instance of the logger for the Singleton pattern

public:
    /**
     * @enum Level
     * @brief Enum representing different log levels.
     *
     * These log levels define the severity of the log messages:
     * - None: No logging
     * - Error: For error messages
     * - Warning: For warning messages
     * - Info: For informational messages
     * - Debug: For debug messages
     */
    enum Level {
        None = 0,    ///< No logging
        Error = 1,   ///< Error messages
        Warning = 2, ///< Warning messages
        Info = 3,    ///< Informational messages
        Debug = 4,   ///< Debug messages
    };

    /**
     * @brief Default constructor for the Logger class.
     *
     * Initializes the logger with a default log level.
     */
    Logger();

    /**
     * @brief Default destructor for the Logger class.
     *
     * Cleans up the logger instance when it is destroyed.
     */
    virtual ~Logger() = default;

    /**
     * @brief Retrieves the Singleton instance of the Logger class.
     * @return A pointer to the static instance of Logger.
     *
     * This method ensures that only one instance of Logger exists in the application.
     */
    static Logger &getInstance()
    {
      static Logger instance;
      return instance;
    }

    /**
     * @brief Sets the logging level.
     * @param level The log level to set.
     *
     * This method changes the logging level to control the verbosity of log messages.
     */
    void setLevel(Level level);

    /**
     * @brief Gets the default log level.
     * @return The default log level.
     *
     * This method retrieves the default log level.
     */
    static Level getDefaultLevel();

    /**
     * @brief Converts the log level enum to a string representation.
     * @param level The log level to convert.
     * @return The string representation of the log level.
     */
    static std::string getLevelString(Level level);

    /**
     * @brief Gets the current log level.
     * @return The current log level.
     */
    [[nodiscard]] Level getLevel() const;

    /**
     * @brief Converts a log message to a string.
     * @param level The level of the log message.
     * @param message The message to log.
     * @return An optional string containing the formatted log message.
     *
     * This method allows for custom formatting of log messages.
     */
    virtual std::string log2String(Level level, const std::string &message);

    /**
     * @class LogLevel
     * @brief A helper class for logging messages at different log levels.
     *
     * This class provides methods to log messages at different levels such as:
     * - None
     * - Error
     * - Warning
     * - Info
     * - Debug
     */
    class LogLevel {
    private:
        Logger *logger_; ///< The logger instance to log messages

    public:
        /**
         * @brief Constructor for LogLevel class.
         * @param logger The logger instance used to log messages.
         */
        explicit LogLevel(Logger *logger) : logger_(logger) {}

        /**
         * @brief Formats a log message with variable arguments.
         * @param message The message format.
         * @param args The variable arguments for the message.
         * @return A formatted string for the log message.
         */
        static std::string argsFormat(const char *message, va_list args);

        /**
         * @brief Logs a message with 'None' level (no logging).
         * @param message The message to log.
         */
        void None(const char *message, ...);

        /**
         * @brief Logs a message with 'Error' level.
         * @param message The message to log.
         */
        void Error(const char *message, ...);

        /**
         * @brief Logs a message with 'Info' level.
         * @param message The message to log.
         */
        void Info(const char *message, ...);

        /**
         * @brief Logs a message with 'Warning' level.
         * @param message The message to log.
         */
        void Warning(const char *message, ...);

        /**
         * @brief Logs a message with 'Debug' level.
         * @param message The message to log.
         */
        void Debug(const char *message, ...);
    };

    // LogLevel instance to log messages at different levels
    LogLevel Log = LogLevel(this);

protected:
    Level level_; ///< The current log level
};

#endif //FUSION_SENS_LOGGER_H
