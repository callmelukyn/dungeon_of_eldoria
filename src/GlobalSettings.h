//
// Created by vitab on 10.12.2024.
//

#ifndef GLOBALSETTINGS_H
#define GLOBALSETTINGS_H
#include <Windows.h>
#define COLOR_RED 04
#define COLOR_DEFAULT 07
#define COLOR_SELECTED 112


class GlobalSettings {
public:
    GlobalSettings();

    static void setColor(int color);
};


#endif //GLOBALSETTINGS_H
