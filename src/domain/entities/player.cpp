//
// Created by ivo on 11/16/2024.
//

#include "player.h"

Player::Player(const Role role, const int hp, const int damage, const int armor, const int range)
    : Entity(hp, damage, range, true, Position{5, 1}) {
    m_armors = {};
    m_weapons = {};
    m_potions = {};
    m_role = role;
    m_armor = armor;
    m_range = range;
    m_maxHp = hp;
    m_xp = 0;
    m_level = 1;
    m_coins = 0; //TODO Jen na test, pak zmenit na 0
}

void Player::levelUp() {
    m_level += 1;
    m_xp -= 100;
    addCoins(150);
    switch (m_role) {
        case Role::warrior:
            m_maxHp += 15;
            m_damage += 5;
            break;
        case Role::archer:
            m_maxHp += 10;
            if (m_level % 2 == 0) {
                m_damage += 3;
            }
            break;
        case Role::mage:
            m_maxHp += 3;
            m_damage += 2;
            if (m_level % 2 == 0) {
                m_range += 1;
            }
            break;
    }
}

void Player::checkStatus(const std::function<void()> &changeScreen) {
    if (m_xp >= 100) {
        levelUp();
    } else if (m_hp <= 0) {
        setAlive(false);
        changeScreen();
    }
}

void Player::addWeapon(Weapon *weapon) {
    m_weapons.push_back(weapon);
}

void Player::addArmor(Armor *armor) {
    m_armors.push_back(armor);
}

void Player::addPotion(Potion *potion) {
    m_potions.push_back(potion);
}

void Player::addDamage(const int damage) {
    m_damage += damage;
}

void Player::addHp(const int hp) {
    m_hp += hp;
}

void Player::addMaxHp(const int maxHp) {
    m_maxHp += maxHp;
}

void Player::usePotion() {
    if (m_hp != m_maxHp) {
        if (m_potions.size() > 0) {
            if (m_hp + m_potions.at(0)->getHpGain() >= m_maxHp) {
                m_hp = m_maxHp;
            } else {
                m_hp += m_potions.at(0)->getHpGain();
            }
            m_potions.erase(m_potions.begin() + m_potions.size() - 1);
        }
    }
}

int Player::getTotalDamage() const {
    int damage = m_damage;
    for (const Weapon *weapon: m_weapons) {
        damage += weapon->getDamage();
    }
    return damage;
}

bool Player::weaponOwned(const Weapon *weapon) const {
    for (const Weapon *search: m_weapons) {
        if (search->getId() == weapon->getId()) {
            return true; //Owned
        }
    }
    return false; //Not owned
}

bool Player::armorOwned(const Armor *armor) const {
    for (const Armor *search: m_armors) {
        if (search->getId() == armor->getId()) {
            return true; //Owned
        }
    }
    return false; //Not owned
}

int Player::getTotalDefense() const {
    int defense = m_armor;
    for (const Armor *armor: m_armors) {
        defense += armor->getArmor();
    }
    return defense;
}

int Player::getXp() const {
    return m_xp;
}

int Player::getMaxHp() const {
    return m_maxHp;
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

void Player::addXp(const int xp) {
    m_xp += xp;
}

void Player::addCoins(const int coins) {
    m_coins += coins;
}

void Player::removeCoins(const int coins) {
    m_coins -= coins;
}

int Player::getCoins() const {
    return m_coins;
}

int Player::getRange() const {
    return m_range;
}

int Player::getNumberOfPotions() const {
    return m_potions.size();
}
