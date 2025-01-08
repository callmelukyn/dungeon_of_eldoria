//
// Created by Lukyn on 26.12.2024.
//

#include "weapon.h"
int Weapon::s_counter = 0;

Weapon::Weapon(int damage, int price) {
    m_damage = damage;
    m_price = price;
    s_counter++;
    m_id = s_counter;
}

int Weapon::getDamage() {
    return m_damage;
}

int Weapon::getPrice() {
    return m_price;
}

int Weapon::getId() {
    return m_id;
}
