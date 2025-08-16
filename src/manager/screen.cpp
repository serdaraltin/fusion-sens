#include "config/config.h"
#include "config/bitmap.h"
#include "manager/screen.h"
#include "device/display/ssd1306.h"

#include <Adafruit_GFX.h>
#include <sstream>
#include <logger/serial_logger.h>

SCREEN *SCREEN::instance = nullptr;


SCREEN::SCREEN() {
    if(BOOT_LOGO){
        image(LOGO);
    }
}

void SCREEN::log(const std::string &level, const std::string& message)
{
    std::stringstream output;

    output << "[" << level << "] " << std::endl << message << std::endl;
    ISSD1306.writeText(output.str().c_str(), 1, 1);
}

void SCREEN::text(const char* text)
{
    ISSD1306.writeText(text, 1, 1);
}

void SCREEN::textM(const char* text)
{
    ISSD1306.writeText(text, 2, 1);
}

void SCREEN::image(unsigned char bitmap[])
{
    ISSD1306.drawBitmap(bitmap);
}

void SCREEN::image(unsigned char bitmap[], int color)
{
}

void SCREEN::image(int startX, int startY, unsigned char bitmap[], int color)
{
}
