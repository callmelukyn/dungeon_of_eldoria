//
// Created by Lukyn on 14.12.2024.
//

#ifndef PRISONER_H
#define PRISONER_H
#include "../../map/map.h"
#include "player.h"

class Prisoner {
    Position m_position;

public:
    Prisoner(Position position);

    Position getPosition();

    void rescuePrisoner(Player *player);
};


#endif //PRISONER_H
