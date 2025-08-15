#ifndef FUSION_SENS_LCD_H
#define FUSION_SENS_LCD_H

#define LcdI Lcd::getInstance()

class Lcd{
private:
    static Lcd *instance;

public:
    Lcd();

    ~Lcd() = default;

    static Lcd *getInstance();

    static void imuData();

};

#endif //FUSION_SENS_LCD_H