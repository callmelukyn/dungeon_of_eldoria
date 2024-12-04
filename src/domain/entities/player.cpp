//
// Created by ivo on 11/16/2024.
//

#include "player.h"

#include "../value_objects/screen.h"

Player::Player(const Role role) {
    m_role = role;
    m_xp = 0;
    m_hp = 100;
    m_coins = 0;
    m_numberOfPotions = 0;
    m_playerPosition = Position(4, 7);
    switch (role) {
        case Role::warrior:
            m_damage = 15;
            m_armor = 15;
            m_range = 1;
            break;
        case Role::archer:
            m_damage = 12;
            m_armor = 8;
            m_range = 3;
            break;
        case Role::mage:
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

int Player::getHp() const {
    return m_hp;
}

int Player::getXp() const {
    return m_xp;
}

int Player::getCoins() const {
    return m_coins;
}

int Player::getNumberOfPotions() const {
    return m_numberOfPotions;
}

void Player::movePlayer(const char key, Screen currentScreen) {
    if (Screen::game == currentScreen) {
        switch (key) {
            case 'w':
                m_playerPosition.y -= 1;
                break;
            case 's':
                m_playerPosition.y += 1;
                break;
            case 'a':
                m_playerPosition.x -= 1;
                break;
            case 'd':
                m_playerPosition.x += 1;
                break;
            default: break;
        }
    }
}

void Player::setPlayerPosition(const Position playerPosition) {
    m_playerPosition = playerPosition;
}

Position Player::getPlayerPosition() const {
    return m_playerPosition;
}




