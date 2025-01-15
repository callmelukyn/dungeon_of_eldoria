//
// Created by Lukyn on 14.12.2024.
//

#include "enemy.h"

#include <iostream>

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

int Enemy::getPotionDropChance() const {
    return m_potionDropChance;
}

void Enemy::moveEnemy(const std::vector<Map *> &maps, const int currentLevel,
                      const Player *player, const char keyboardKey) {
    Map *map = maps[currentLevel];
    Position nextPosition = m_position;

    // if (!m_aggroed && isInRange(player->getPosition(), m_position)) {
    //     m_aggroed = true;
    // } else if (!m_aggroed && (player->isInRange(player->getPosition(), m_position)
    //                           && keyboardKey == 'f')) {
    //     m_hp -= player->getDamage();
    //     m_aggroed = true;
    // }
    // if (!player->isInRange(player->getPosition(), m_position) && keyboardKey == 'f') {
    //     std::cout << "no range\r";
    // } else {
    //     std::cout << "\b           \r";
    // }

    if (m_aggroed && m_alive) {
        // if (player->isInRange(player->getPosition(), m_position) && keyboardKey == 'f') {
        //     m_hp -= player->getDamage();
        // }
        if (keyboardKey == 'f' || GlobalSettings::movementKeys(keyboardKey)) {
            if (Position::getDistanceX(player->getPosition().x, nextPosition.x) >
                Position::getDistanceX(player->getPosition().y, nextPosition.y)) {
                player->getPosition().x > nextPosition.x
                    ? nextPosition.x += 1
                    : nextPosition.x -= 1;
            } else {
                player->getPosition().y > nextPosition.y
                    ? nextPosition.y += 1
                    : nextPosition.y -= 1;
            }
        }
    }

    const char nextTile = map->assignTilePosition(nextPosition); // Access the tile at the next position
    // Movement only through '.'
    if (nextTile == '.' && m_alive) {
        map->clearCharacterFromPosition(m_position);
        m_position = nextPosition;
        map->putCharacterInPosition(m_position, '!');
    }
}

bool Enemy::isAggroed() const {
    return m_aggroed;
}

void Enemy::setAggro(const bool aggroed) {
    m_aggroed = aggroed;
}

void Enemy::checkEnemyHp(const std::vector<Map *> &maps, const int currentLevel) {
    if (m_hp <= 0) {
        const KillEnemy *killEnemy = new KillEnemy(this, maps, currentLevel);
        delete killEnemy;
    }
}

