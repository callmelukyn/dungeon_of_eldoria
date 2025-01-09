//
// Created by Lukyn on 14.12.2024.
//

#ifndef PRISONER_H
#define PRISONER_H
#include "player.h"

class Prisoner {
    Position m_position;

public:
    explicit Prisoner(Position position);

    Position getPosition() const;

    void rescuePrisoner(Player *player);
};


#endif //PRISONER_H
