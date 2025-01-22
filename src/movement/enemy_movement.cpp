#include "enemy_movement.h"

#include "../tools/global_settings.h"

EnemyMovement::EnemyMovement(Enemy *enemy) {
    m_enemy = enemy;
}

void EnemyMovement::moveEnemy(const std::vector<Map *> &maps, const int currentLevel, const Player *player,
                              const char keyboardKey) {
    if (!m_enemy->isAlive()) {
        return;
    }

    if (!m_enemy->isAggroed() || (!GlobalSettings::movementKeys(keyboardKey) && keyboardKey != 'f')) {
        return;
    }

    Map *map = maps[currentLevel];
    Position nextPosition = calculateNextPosition(player);

    if (canMoveToNextPosition(map, nextPosition)) {
        updatePosition(map, nextPosition);
    }
}

Position EnemyMovement::calculateNextPosition(const Player *player) const {
    Position nextPosition = m_enemy->getPosition();

    if (Position::getDistanceX(player->getPosition().x, nextPosition.x) >
        Position::getDistanceX(player->getPosition().y, nextPosition.y)) {
        nextPosition.x += player->getPosition().x > nextPosition.x ? 1 : -1;
    } else {
        nextPosition.y += player->getPosition().y > nextPosition.y ? 1 : -1;
    }

    return nextPosition;
}

bool EnemyMovement::canMoveToNextPosition(const Map *map, const Position nextPosition) {
    return map->assignTilePosition(nextPosition) == '.';
}

void EnemyMovement::updatePosition(Map *map, const Position nextPosition) const {
    map->clearCharacterFromPosition(m_enemy->getPosition());
    m_enemy->setPosition(nextPosition);
    map->putCharacterInPosition(m_enemy->getPosition(), '!');
}
