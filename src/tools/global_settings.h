//
// Created by vitab on 10.12.2024.
//

#ifndef GLOBAL_SETTINGS_H
#define GLOBAL_SETTINGS_H
#include <ctime>
#include <windows.h>

#define COLOR_RED 04
#define COLOR_GREEN 02
#define COLOR_DEFAULT 07
#define COLOR_SELECTED 112
#define COLOR_YELLOW 06
#define ESCAPE 27
#define ENTER 13
#define KEY_W 119
#define KEY_S 115
#define KEY_A 97
#define KEY_D 100
#define KEY_F 102

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
