//
// Created by Lukyn on 21.12.2024.
//

#ifndef ENTITY_H
#define ENTITY_H
#include "../../map/position.h"


class Entity {
protected:
    int m_hp;
    int m_damage;
    bool m_alive;
    Position m_position;

public:
    Entity(int hp, int damage, bool alive, Position position);
};


#endif //ENTITY_H
