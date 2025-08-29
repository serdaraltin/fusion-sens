//
// Created by main on 29.08.2025.
//

#ifndef SCREEN_H
#define SCREEN_H


// SCREEN Configuration ============================================

/**
 * @def SCREEN_I2C
 * @brief The I2C address of the SCREEN screen.
 *
 * This defines the I2C address for the SCREEN screen, set to 0x3C.
 */
#define SCREEN_I2C 0x3C

/**
 * @def OLED_RESET
 * @brief The reset pin for the OLED screen.
 *
 * This defines the reset pin for the OLED screen, set to -1 if no reset pin is needed.
 */
#define OLED_RESET (-1)

/**
 * @def SCREEN_WIDTH
 * @brief The width of the SCREEN screen.
 *
 * This defines the width of the OLED screen in pixels, set to 128.
 */
#define SCREEN_WIDTH 128

/**
 * @def SCREEN_HEIGHT
 * @brief The height of the SCREEN screen.
 *
 * This defines the height of the OLED screen in pixels, set to 64.
 */
#define SCREEN_HEIGHT 64

#define SCREEN_LINE_LIMIT 8
#define SCREEN_CHARACTER_LIMIT 20

/**
 * @def BOOT_LOGO
 * @brief Whether to display the boot logo.
 *
 * This defines whether to display the boot logo on the screen during startup. Set to `true` to enable.
 */
#define BOOT_LOGO true

#endif //SCREEN_H
