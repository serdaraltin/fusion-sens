#ifndef FUSION_SENS_SCREEN_H
#define FUSION_SENS_SCREEN_H

#define ISCREEN SCREEN::getInstance()

#include <logger/logger.h>

class SCREEN{
private:
    static SCREEN *instance;

    static void logPush(const std::string& text);
    static void logWrap(const std::string& text, size_t limit);
    static std::string logGetAll();
public:
    SCREEN();

    ~SCREEN() = default;


    static SCREEN &getInstance()
    {
        static SCREEN instance;
        return instance;
    }


    static void log(const std::string& level, const std::string& message);

    static void text(const std::string& text);
    static void textM(const std::string& text);

    static void image(unsigned char bitmap[]);
    static void image(unsigned char bitmap[], int color);
    static void image(int startX, int startY, unsigned char bitmap[], int color);
};

#endif //FUSION_SENS_SCREEN_H