//
// Created by Lukyn on 14.12.2024.
//

#include "enemy.h"

#include "player.h"
#include "../../tools/global_settings.h"

Enemy::Enemy(const EnemyType enemyType, const int hp, const int damage, const int coinReward, const int xpReward,
             const int potionDropChance, const int range, const Position enemyPosition)
    : Entity(hp, damage, true, enemyPosition) {
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

int Enemy::getHp() const {
    return m_hp;
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

void Enemy::moveEnemy(const Screen currentScreen, const std::vector<Map *> &maps, const int currentLevel,
                      const Player *player, const char keyboardKey) {
    if (Screen::game == currentScreen) {
        Map *map = maps[currentLevel];
        Position nextPosition = m_position;
        const unsigned int distanceX = abs(static_cast<int>(player->getPlayerPosition().x - nextPosition.x));
        const unsigned int distanceY = abs(static_cast<int>(player->getPlayerPosition().y - nextPosition.y));

        if (!m_aggroed && (distanceX <= m_range && distanceY <= m_range)) {
            m_aggroed = true;
        } else if (!m_aggroed && (distanceX <= player->getRange() && distanceY <= player->getRange()
                                  && keyboardKey == 'f')) {
            m_hp -= player->getDamage();
            m_aggroed = true;
        }

        if (m_aggroed && m_alive) {
            if (player->getRange() >= distanceX && player->getRange() >= distanceY && keyboardKey == 'f') {
                m_hp -= player->getDamage();
            }
            if (keyboardKey == 'f' || GlobalSettings::movementKeys(keyboardKey)) {
                if (distanceX > distanceY) {
                    player->getPlayerPosition().x > nextPosition.x
                        ? nextPosition.x += 1
                        : nextPosition.x -= 1;
                } else {
                    player->getPlayerPosition().y > nextPosition.y
                        ? nextPosition.y += 1
                        : nextPosition.y -= 1;
                }
            }
        }

        if (m_hp <= 0) {
            m_aggroed = false;
            m_alive = false;
            map->clearCharacterFromPosition(m_position);
            m_position = Position{0, 0};
            return;
        }

        const char nextTile = map->assignTilePosition(nextPosition); // Access the tile at the next position
        // Movement only through '.'
        if (nextTile == '.' && m_alive) {
            map->clearCharacterFromPosition(m_position);
            m_position = nextPosition;
            map->putCharacterInPosition(m_position, '!');
        }
    }
}

Position Enemy::getEnemyPosition() const {
    return m_position;
}

bool Enemy::isAggroed() const {
    return m_aggroed;
}
