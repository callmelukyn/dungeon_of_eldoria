//
// Created by Lukyn on 14.12.2024.
//

#include "enemy.h"

Enemy::Enemy(EnemyType enemyType, int hp, int damage, int coinReward, int xpReward, int potionDropChance) {
    m_enemyType = enemyType;
    m_hp = hp;
    m_damage = damage;
    m_coinReward = coinReward;
    m_xpReward = xpReward;
    m_potionDropChance = potionDropChance;
    m_alive = true;
}

int Enemy::getDamage() {
    return m_damage;
}

int Enemy::getHp() {
    return m_hp;
}

int Enemy::getCoinReward() {
    return m_coinReward;
}

int Enemy::getXpReward() {
    return m_xpReward;
}

int Enemy::getPotionDropChance() {
    return m_potionDropChance;
}
