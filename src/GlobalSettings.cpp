//
// Created by vitab on 10.12.2024.
//

#include "GlobalSettings.h"


GlobalSettings::GlobalSettings() {
}

void GlobalSettings::setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
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






