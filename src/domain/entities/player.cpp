//
// Created by ivo on 11/16/2024.
//

#include "player.h"

Player::Player(Role role) {
    m_role = role;
    m_xp = 0;
    m_hp = 100;
    m_coins = 0;
    m_numberOfPotions = 0;
    m_position = {0, 0};
    switch (role) {
        case Role::Warrior:
            m_damage = 15;
            m_armor = 15;
            m_range = 1;
            break;
        case Role::Archer:
            m_damage = 12;
            m_armor = 8;
            m_range = 3;
            break;
        case Role::Mage:
            m_damage = 10;
            m_armor = 5;
            m_range = 5;
            break;
    }
}

void Player::addPotion() {
    m_numberOfPotions += 1;
}

void Player::usePotion() {
    if (m_numberOfPotions > 0) {
        Potion potion;
        if (m_hp + potion.m_hpGain >= 100) {
            //TODO Mozna vyresit, aby nesel potion pouzit s plnymi zivoty
            m_hp = 100;
        } else if (m_hp + potion.m_hpGain < 100) {
            m_hp += potion.m_hpGain;
        }
        m_numberOfPotions -= 1;
    }
}

int Player::getHp() {
    return m_hp;
}



