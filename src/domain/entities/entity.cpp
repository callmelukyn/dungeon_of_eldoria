//
// Created by Lukyn on 21.12.2024.
//

#include "entity.h"

Entity::Entity(const int hp, const int damage, const bool alive, const Position position): m_position(position) {
    m_hp = hp;
    m_damage = damage;
    m_alive = alive;
}
