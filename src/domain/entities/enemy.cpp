//
// Created by Lukyn on 14.12.2024.
//

#include "enemy.h"

#include "player.h"
#include "../../commands/kill_enemy.h"
#include "../../tools/global_settings.h"

Enemy::Enemy(const EnemyType enemyType, const int hp, const int damage, const int coinReward, const int xpReward,
             const int potionDropChance, const int range, const Position enemyPosition)
    : Entity(hp, damage, range, true, enemyPosition) {
    m_enemyType = enemyType;
    m_coinReward = coinReward;
    m_xpReward = xpReward;
    m_potionDropChance = potionDropChance;
    m_range = range;
    m_aggroed = false;
}

int Enemy::getDamage() const {
    return m_damage;
}

int Enemy::getCoinReward() const {
    return m_coinReward;
}

int Enemy::getXpReward() const {
    return m_xpReward;
}

void Enemy::dropPotion(Player *player) const {
    if (GlobalSettings::getRandomNumber(100) <= m_potionDropChance) {
        player->addPotion(new Potion());
    }
}

bool Enemy::isAggroed() const {
    return m_aggroed;
}

void Enemy::setAggro(const bool aggroed) {
    m_aggroed = aggroed;
}

void Enemy::checkEnemyHp(const std::vector<Map *> &maps, Player *player, const int currentLevel) {
    if (!m_alive) {
        return;
    }
    if (m_hp <= 0) {
        const KillEnemy *killEnemy = new KillEnemy(this, maps, currentLevel);
        delete killEnemy;
        player->addXp(m_xpReward);
        dropPotion(player);

        // Cool system kterej jsem nakonec nepotreboval
        // protoze mi stacila jedna funkce ale je mi lito ho mazat uz

        // std::unordered_map<EnemyType, int> xpBasedOnEnemyKilled = {
        //     {EnemyType::basilisk, m_xpReward},
        //     {EnemyType::gargoyle, 10},
        //     {EnemyType::ghoul, 10},
        //     {EnemyType::mummy, 10},
        //     {EnemyType::necromancer, 10},
        // };
        // auto it = xpBasedOnEnemyKilled.find(m_enemyType);
        // if (it != xpBasedOnEnemyKilled.end()) {
        //     player->addXp(it->second); // Add the XP to the player
        // }
    }
}

int Enemy::randomDamage() const {
    const int max = getDamage() + 2;
    const int min = getDamage() - 2;
    const int range = max - min + 1;
    return rand() % range + min;
}

EnemyType Enemy::getEnemyType() const {
    return m_enemyType;
}

