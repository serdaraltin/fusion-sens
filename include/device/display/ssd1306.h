//
// Created by Serdar on 7.11.2024.
//

#ifndef FUSION_SENS_SSD1306_H
#define FUSION_SENS_SSD1306_H


class SSD1306 {
private:
    static SSD1306 *instance;
    static void textInit();
    static void textWrite(const char *text, int size);
public:
    SSD1306();
    ~SSD1306() = default;
    static SSD1306 *getInstance();


    static void text(const char *text);
    static void textM(const char *text);

    static void image(unsigned char bitmap[]);
    static void image(unsigned char bitmap[], int color);
    static void image(int startX, int startY, unsigned char bitmap[], int color);
};


#endif //FUSION_SENS_SSD1306_H
