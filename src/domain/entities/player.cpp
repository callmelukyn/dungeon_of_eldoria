//
// Created by ivo on 11/16/2024.
//

#include "player.h"

#include "../../tools/globalSettings.h"
#include "../value_objects/screen.h"

Player::Player(const Role role, const int hp, const int damage, const int armor, const int range,
               bool alive): Entity(hp, damage, alive, Position{5, 1}) {
    m_role = role;
    m_armor = armor;
    m_range = range;
    m_maxHp = hp;
    m_xp = 0;
    m_level = 1;
    m_coins = 10000; //TODO Jen na test, pak zmenit na 0
    m_numberOfPotions = 0;
}

void Player::levelUp() {
    m_level += 1;
    m_xp -= 100;
    switch (m_role) {
        case Role::warrior:
            m_maxHp += 10;
            m_damage += 7;
            break;
        case Role::archer:
            m_maxHp += 8;
            m_damage += 7;
            break;
        case Role::mage:
            m_maxHp += 5;
            m_damage += 15;
            break;
    }
}

void Player::checkLevelStatus() {
    if (m_xp >= 100) {
        levelUp();
    }
}

void Player::addPotion() {
    m_numberOfPotions += 1;
}

void Player::addDamage(int damage) {
    m_damage += damage;
}

int Player::addHp(int hp) {
    m_hp += hp;
}

int Player::addMaxHp(int maxHp) {
    m_maxHp += maxHp;
}

void Player::addArmor(int armor) {
    m_armor += armor;
}

/*
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
} */

int Player::getHp() const {
    return m_hp;
}

int Player::getXp() const {
    return m_xp;
}

int Player::getLevel() const {
    return m_level;
}

int Player::getDamage() const {
    return m_damage;
}

Role Player::getRole() const {
    return m_role;
}

int Player::addXp(int xp) {
    m_xp += xp;
}

void Player::addCoins(int coins) {
    m_coins += coins;
}

void Player::removeCoins(int coins) {
    m_coins -= coins;
}

int Player::getCoins() const {
    return m_coins;
}

int Player::getNumberOfPotions() const {
    return m_numberOfPotions;
}

void Player::movePlayer(const char keyboardKey, const Screen currentScreen, const std::vector<Map *> &maps,
                        const int currentLevel, const std::function<void()> &nextLevel,
                        const std::vector<Enemy *> &enemies) {
    if (Screen::game == currentScreen) {
        Map *map = maps[currentLevel];
        Position nextPosition = m_position;

        for (const Enemy *enemy: enemies) {
            if (enemy->isAggroed()) {
                return;
            }
        }
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
            map->clearCharacterFromPosition(m_position);
            m_position = nextPosition;
            map->putCharacterInPosition(m_position, '@');
        }
        if (nextTile == '|') {
            nextLevel();
            map->clearCharacterFromPosition(m_position);
        }
    }
}

void Player::setPlayerPosition(const Position playerPosition) {
    m_position = playerPosition;
}

Position Player::getPlayerPosition() const {
    return m_position;
}


