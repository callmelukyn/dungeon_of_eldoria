//
// Created by Lukyn on 14.12.2024.
//

#include "enemy.h"

#include "../../tools/globalSettings.h"

bool Enemy::m_aggroed = false;

Enemy::Enemy(EnemyType enemyType, int hp, int damage, int coinReward, int xpReward,
             int potionDropChance, int range, Position enemyPosition): m_enemyPosition(enemyPosition) {
    m_enemyType = enemyType;
    m_hp = hp;
    m_damage = damage;
    m_coinReward = coinReward;
    m_xpReward = xpReward;
    m_potionDropChance = potionDropChance;
    m_range = range;
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

bool Enemy::getAggroed() const {
    return m_aggroed;
}

void Enemy::moveEnemy(const Screen currentScreen, const std::vector<Map *> &maps, const int currentLevel,
                      const Player *player, const char keyboardKey) {
    if (Screen::game == currentScreen) {
        Map *map = maps[currentLevel];
        Position nextPosition = m_enemyPosition;
        const unsigned int distanceX = abs(static_cast<int>(player->getPlayerPosition().x - nextPosition.x));
        const unsigned int distanceY = abs(static_cast<int>(player->getPlayerPosition().y - nextPosition.y));

        if (distanceX <= m_range && distanceY <= m_range) {
            m_aggroed = true;
        }
        if (m_aggroed) {
            if (keyboardKey == KEYBOARD_SMALL_W || keyboardKey == KEYBOARD_SMALL_S || keyboardKey ==
                KEYBOARD_SMALL_D ||
                keyboardKey == KEYBOARD_SMALL_A || keyboardKey == KEYBOARD_CAPITAL_W || keyboardKey ==
                KEYBOARD_CAPITAL_S ||
                keyboardKey == KEYBOARD_CAPITAL_A || keyboardKey == KEYBOARD_CAPITAL_D) {
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

        const char nextTile = map->assignTilePosition(nextPosition); // Access the tile at the next position
        // Movement only through '.'
        if (nextTile == '.') {
            map->clearCharacterFromPosition(m_enemyPosition);
            m_enemyPosition = nextPosition;
            map->putCharacterInPosition(m_enemyPosition, '!');
        }
    }
}

Position Enemy::getEnemyPosition() {
    return m_enemyPosition;
}

bool Enemy::isAggroed() {
    return m_aggroed;
}
