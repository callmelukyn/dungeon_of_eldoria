//
// Created by Lukyn on 26.12.2024.
//

#include "weapon.h"

Weapon::Weapon(int damage, int price) {
    m_damage = damage;
    m_price = price;
}

int Weapon::getDamage() {
    return m_damage;
}

int Weapon::getPrice() {
    return m_price;
}
