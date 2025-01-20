//
// Created by Lukyn on 14.12.2024.
//

#ifndef PRISONER_H
#define PRISONER_H
#include "../entities/player.h"

class Prisoner {
    Position m_position;

public:
    explicit Prisoner(Position position);

    Position getPosition() const;

    void setPosition(Position position);

    void rescuePrisoner(Player *player, const std::vector<Map *> &maps, int currentLevel);
};


#endif //PRISONER_H
