//
// Created by Lukyn on 21.12.2024.
//

#include "entity.h"

Entity::Entity(int hp, int damage, bool alive, Position position): m_position(position) {
    m_hp = hp;
    m_damage = damage;
    m_alive = alive;
}
