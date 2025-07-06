#include "device/display/lcd.h"
#include "config/config.h"
#include "logger/serial_logger.h"
#include "Adafruit_SSD1306.h"
#include <SPI.h>


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Lcd *Lcd::instance = nullptr;

Lcd *Lcd::getInstance() {
    if(instance == nullptr)
        instance = new Lcd();
    return instance;
}

Lcd::Lcd() {
    SerialLog.Info("SSD1306 initializing...");
    while (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_I2C)) {
        SerialLog.Warning("SSD1306 allocation failed!");
        delay(2000);
    }
    SerialLog.Info("SSD1306 allocation successful.");

    if(BOOT_LOGO){
        display.clearDisplay();
        display.display();
    }
}

void Lcd::imuData() {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);

    display.println(F("Test"));
    display.display();
}
