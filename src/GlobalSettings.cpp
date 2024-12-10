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

