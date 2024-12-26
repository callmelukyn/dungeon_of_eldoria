//
// Created by Lukyn on 26.12.2024.
//

#include "armor.h"

Armor::Armor(int armor, int price) {
    m_armor = armor;
    m_price = price;
}

int Armor::getArmor() {
    return m_armor;
}

int Armor::getPrice() {
    return m_price;
}
