//
// Created by ivo on 11/16/2024.
//

#include "player.h"

#include "../../GlobalSettings.h"
#include "../value_objects/screen.h"

Player::Player(const Role role) : m_playerPosition(Position{2, 2}) {
    m_role = role;
    m_xp = 0;
    m_hp = 100;
    m_coins = 0;
    m_numberOfPotions = 0;
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

void Player::movePlayer(const char keyboardKey, const Screen currentScreen, const std::vector<Map *> &maps,
                        const int currentLevel, const std::function<void()> &nextLevel) {
    if (Screen::game == currentScreen) {
        Map *map = maps[currentLevel];
        Position nextPosition = m_playerPosition;

        // Calculate the next position based on the input key
        switch (keyboardKey) {
            case KEYBOARD_SMALL_W:
            case KEYBOARD_CAPITAL_W:
                nextPosition.y -= 1;
                break;
            case KEYBOARD_SMALL_S:
            case KEYBOARD_CAPITAL_S:
                nextPosition.y += 1;
                break;
            case KEYBOARD_SMALL_A:
            case KEYBOARD_CAPITAL_A:
                nextPosition.x -= 1;
                break;
            case KEYBOARD_SMALL_D:
            case KEYBOARD_CAPITAL_D:
                nextPosition.x += 1;
                break;
            default:
                break;
        }

        const char nextTile = map->assignTilePosition(nextPosition); // Access the tile at the next position
        // Movement only through '.' or doors
        if (nextTile == '.') {
            map->clearCharacterFromPosition(m_playerPosition);
            m_playerPosition = nextPosition;
            map->putCharacterInPosition(m_playerPosition, '@');
        }
        if (nextTile == '|') {
            nextLevel();
            map->clearCharacterFromPosition(m_playerPosition);
        }
    }
}

void Player::setPlayerPosition(const Position playerPosition) {
    m_playerPosition = playerPosition;
}

Position Player::getPlayerPosition() const {
    return m_playerPosition;
}


