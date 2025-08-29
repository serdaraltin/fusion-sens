#include "config.h"
#include "manager/screen.h"
#include "device/display/ssd1306.h"
#include "screen.h"
#include "static.h"

#include <Adafruit_GFX.h>
#include <sstream>
#include <vector>


SCREEN *SCREEN::instance = nullptr;

std::vector<std::string> log_vector;

SCREEN::SCREEN() {
    if(BOOT_LOGO){
        image(LOGO);
    }
}

void SCREEN::logPush(const std::string& text)
{
    if(log_vector.size() >= SCREEN_LINE_LIMIT)
    {
        log_vector.erase(log_vector.begin());
    }
    log_vector.push_back(text);

}

void SCREEN::logWrap(const std::string& text, const size_t limit)
{
    size_t start = 0;
    while(start < text.size())
    {
        size_t end = start + limit;
        if(end >= text.size())
            end = text.size();
        else
        {
            const size_t break_pos = text.find_last_of(" ,.;=", end-1);
            if(break_pos == std::string::npos && break_pos >= start)
            {
                end = break_pos+1;
            }
        }

        std::string part = text.substr(start, end-start);
        logPush(part);
        start = end;
    }
}

std::string SCREEN::logGetAll()
{
    std::stringstream ss;
    for(const std::string & i : log_vector)
    {
        ss << i << std::endl;
    }
    return ss.str();
}

void SCREEN::log(const std::string &level, const std::string& message)
{
    logWrap(message, SCREEN_CHARACTER_LIMIT);

    ISSD1306.writeText(logGetAll().c_str(), 1, 1);
}

void SCREEN::text(const std::string& text)
{
    ISSD1306.writeText(text.c_str(), 1, 1);
}

void SCREEN::textM(const std::string& text)
{
    ISSD1306.writeText(text.c_str(), 2, 1);
}

void SCREEN::image(unsigned char bitmap[])
{
    ISSD1306.drawBitmap(bitmap);
}

void SCREEN::image(unsigned char bitmap[], const int color)
{
    ISSD1306.drawBitmap(bitmap, color);
}

void SCREEN::image(const int startX, const int startY, unsigned char bitmap[], const int color)
{
    ISSD1306.drawBitmap(startX, startY, bitmap, color);
}
