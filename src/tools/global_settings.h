//
// Created by vitab on 10.12.2024.
//

#ifndef GLOBAL_SETTINGS_H
#define GLOBAL_SETTINGS_H
#include <windows.h>
#include <cstdlib>
#include <ctime>

#define COLOR_RED 04
#define COLOR_DEFAULT 07
#define COLOR_SELECTED 112
#define COLOR_YELLOW 06
#define KEYBOARD_ESC 27
#define KEYBOARD_ENTER 13
#define KEYBOARD_CAPITAL_W 87
#define KEYBOARD_SMALL_W 119
#define KEYBOARD_CAPITAL_S 83
#define KEYBOARD_SMALL_S 115
#define KEYBOARD_CAPITAL_A 65
#define KEYBOARD_SMALL_A 97
#define KEYBOARD_CAPITAL_D 68
#define KEYBOARD_SMALL_D 100

class GlobalSettings {
    static bool supportsANSI();

public:
    GlobalSettings();

    static int getRandomNumber(int maxNumber);

    static void setColor(int color);

    static BOOL setFontSize();

    static void hideCursor();

    static void clearConsoleOnNewScreen();

    static void clearScreen();

    static void turnOnSupportForANSI();

    static bool movementKeys(char keyboardKey);
};


#endif //GLOBAL_SETTINGS_H
