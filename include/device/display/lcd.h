#include "config/config.h"

#define LcdI Lcd::getInstance()

class Lcd{
private:
    static Lcd *instance;

public:
    Lcd();

    ~Lcd() = default;

    static Lcd *getInstance();

    void imuData();
};

