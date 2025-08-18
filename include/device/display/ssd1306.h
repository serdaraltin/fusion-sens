//
// Created by Serdar on 7.11.2024.
//

#ifndef FUSION_SENS_SSD1306_H
#define FUSION_SENS_SSD1306_H

#define ISSD1306 SSD1306::getInstance()
#include <cstdint>

class SSD1306 {
private:
    static SSD1306 *instance;

public:
    SSD1306();
    ~SSD1306() = default;
    static SSD1306 &getInstance()
    {
        static SSD1306 instance;
        return instance;
    }

    static void init();

    static void testanimate();
    static void writeText(const char *text, int size, int color);

    static void drawBitmap(unsigned char bitmap[]);
    static void drawBitmap(unsigned char bitmap[], int color);
    static void drawBitmap(int startX, int startY, unsigned char bitmap[], int color);
};

#endif //FUSION_SENS_SSD1306_H
