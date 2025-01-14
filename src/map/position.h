//
// Created by Lukyn on 27.11.2024.
//


#ifndef POSITION_H
#define POSITION_H
#include <iostream>

struct Position {
    unsigned int x;
    unsigned int y;

    static unsigned int getDistanceX(const unsigned int playerPositionX, const unsigned int otherPositionX) {
        return abs(static_cast<int>(playerPositionX - otherPositionX));
    }

    static unsigned int getDistanceY(const unsigned int playerPositionY, const unsigned int otherPositionY) {
        return abs(static_cast<int>(playerPositionY - otherPositionY));
    }
};

#endif //POSITION_H
