//
// Created by Serdar on 5.11.2024.
//

#include "logger/logger.h"
#include "config/config.h"
#include <sstream>
#include <cstdarg>

Logger *Logger::instance = nullptr;
//Logger::LogLevel *Log;

Logger::Logger() {
    level_ = getDefaultLevel();
}

Logger *Logger::getInstance() {
    if(instance == nullptr) {
        instance = new Logger();
        // Log = Logger::LogLevel(instance);
    }
    return instance;
}

void Logger::setLevel(Logger::Level level) {
    this->level_ = level;
}

Logger::Level Logger::getDefaultLevel() {
    return Logger::Info;
}

Logger::Level Logger::getLevel() const {
    return level_;
}

std::string Logger::getLevelString(Logger::Level level) {
    switch (level) {
        case Level::None: return "None";
        case Level::Error: return "Error";
        case Level::Warning: return "Warning";
        case Level::Info: return "Info";
        case Level::Debug: return "Debug";
        default: return "None";
    }
}

std::string Logger::log2String(Logger::Level level, const std::string &message) {
    std::stringstream output;
    if(level > level_)
        return output.str();
    output << "[" << APP_NAME << "] [" << getLevelString(level) << "] " << message;
    return output.str();
}

std::string Logger::LogLevel::argsFormat(const char *message, va_list args) {
    char buffer[256];
    vsniprintf(buffer, sizeof(buffer), message, args);
    return buffer;
}

void Logger::LogLevel::None(const char *message, ...) {
    va_list args;
    va_start(args, message);
    std::string formattedMessage = argsFormat(message, args);
    va_end(args);

    logger_->log2String(Level::None, formattedMessage);
}

void Logger::LogLevel::Error(const char *message, ...) {
    va_list args;
    va_start(args, message);
    std::string formattedMessage = argsFormat(message, args);
    va_end(args);

    logger_->log2String(Level::Error, formattedMessage);
}

void Logger::LogLevel::Warning(const char *message, ...) {
    va_list args;
    va_start(args, message);
    std::string formattedMessage = argsFormat(message, args);
    va_end(args);

    logger_->log2String(Level::Warning, formattedMessage);
}

void Logger::LogLevel::Debug(const char *message, ...) {
    va_list args;
    va_start(args, message);
    std::string formattedMessage = argsFormat(message, args);
    va_end(args);

    logger_->log2String(Level::Debug, formattedMessage);
}

void Logger::LogLevel::Info(const char *message, ...) {
    va_list args;
    va_start(args, message);
    std::string formattedMessage = argsFormat(message, args);
    va_end(args);

    logger_->log2String(Level::Info, formattedMessage);
}

