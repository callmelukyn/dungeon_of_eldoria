//
// Created by vitab on 10.12.2024.
//

#include "global_settings.h"

#include <iostream>

GlobalSettings::GlobalSettings() = default;

void GlobalSettings::setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int GlobalSettings::getRandomNumber(int maxNumber) {
    int seed = time(0);
    srand(seed);
    int generatedNumber = 1 + rand() % maxNumber;
    return generatedNumber;
}

BOOL GlobalSettings::setFontSize() {
    COORD fontSize = {25, 25};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX info{sizeof(CONSOLE_FONT_INFOEX)};
    if (!GetCurrentConsoleFontEx(output, false, &info))
        return false;
    info.dwFontSize = fontSize;
    return SetCurrentConsoleFontEx(output, false, &info);
}

void GlobalSettings::hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);

    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void GlobalSettings::clearConsoleOnNewScreen() {
#ifdef _WIN32
    system("cls");
    // COORD topLeft = {0, 0};
    // HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    // DWORD written;
    // CONSOLE_SCREEN_BUFFER_INFO screen;
    //
    // int windowWidth = screen.srWindow.Right - screen.srWindow.Left + 1;
    // int windowHeight = screen.srWindow.Bottom - screen.srWindow.Top + 1;
    // if (windowHeight < screen.dwSize.Y || windowWidth < screen.dwSize.X) {
    //     std::cout << "\x1B[3J";
    // }
    //
    // GetConsoleScreenBufferInfo(console, &screen);
    // FillConsoleOutputCharacterA(
    //     console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    // );
    // FillConsoleOutputAttribute(
    //     console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
    //     screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    // );
    // SetConsoleCursorPosition(console, topLeft);
#else
    system("clear");
#endif
}

void GlobalSettings::clearScreen() {
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO screen;

    // int windowWidth = screen.srWindow.Right - screen.srWindow.Left + 1;
    // int windowHeight = screen.srWindow.Bottom - screen.srWindow.Top + 1;
    // // if (windowHeight < screen.dwSize.Y || windowWidth < screen.dwSize.X) {
    // //     std::cout << "\x1B[3J";
    // // }
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

#else
    system("clear");
#endif
}

void GlobalSettings::turnOnSupportForANSI() {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hStdOut, &mode);
    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hStdOut, mode);
}

bool GlobalSettings::movementKeys(const char keyboardKey) {
    return keyboardKey == KEYBOARD_CAPITAL_W ||
           keyboardKey == KEYBOARD_SMALL_W ||
           keyboardKey == KEYBOARD_CAPITAL_S ||
           keyboardKey == KEYBOARD_SMALL_S ||
           keyboardKey == KEYBOARD_CAPITAL_A ||
           keyboardKey == KEYBOARD_SMALL_A ||
           keyboardKey == KEYBOARD_CAPITAL_D ||
           keyboardKey == KEYBOARD_SMALL_D;
}

bool GlobalSettings::supportsANSI() {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE) {
        return false;
    }

    DWORD mode;
    if (!GetConsoleMode(hStdOut, &mode)) {
        return false;
    }

    // Check if ENABLE_VIRTUAL_TERMINAL_PROCESSING is enabled
    return (mode & ENABLE_VIRTUAL_TERMINAL_PROCESSING) != 0;
}
