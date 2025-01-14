//
// Created by Lukyn on 21.12.2024.
//

#include "entity.h"

Entity::Entity(const int hp, const int damage, const int range, const bool alive, const Position position)
    : m_position(position) {
    m_hp = hp;
    m_damage = damage;
    m_range = range;
    m_alive = alive;
}

int Entity::getHp() const {
    return m_hp;
}

bool Entity::isAlive() const {
    return m_alive;
}

void Entity::setAlive(const bool alive) {
    m_alive = alive;
}

Position Entity::getPosition() const {
    return m_position;
}

void Entity::setPosition(const Position position) {
    m_position = position;
}

bool Entity::isInRange(const Position playerPosition, const Position otherPosition) const {
    if (m_range >= Position::getDistanceX(playerPosition.x, otherPosition.x)
        && m_range >= Position::getDistanceY(playerPosition.y, otherPosition.y)) {
        return true;
    }
    return false;
}


