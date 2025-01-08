//
// Created by Lukyn on 26.12.2024.
//

#include "armor.h"
int Armor::s_counter = 0;

Armor::Armor(int armor, int price) {
    m_armor = armor;
    m_price = price;
    s_counter++;
    m_id = s_counter;
}

int Armor::getArmor() {
    return m_armor;
}

int Armor::getPrice() {
    return m_price;
}

int Armor::getId() {
    return m_id;
}
