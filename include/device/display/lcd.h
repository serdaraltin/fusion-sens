#ifndef FUSION_SENS_LCD_H
#define FUSION_SENS_LCD_H

#define ILcd Lcd::getInstance()

class Lcd{
private:
    static Lcd *instance;

public:
    Lcd();

    ~Lcd() = default;

    static Lcd *getInstance();


    static void text(const char *text);
    static void textM(const char *text);

    static void image(unsigned char bitmap[]);
    static void image(unsigned char bitmap[], int color);
    static void image(int startX, int startY, unsigned char bitmap[], int color);
};

#endif //FUSION_SENS_LCD_H