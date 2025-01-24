#include "player_movement.h"

#include "../tools/global_settings.h"

PlayerMovement::PlayerMovement(Player *player) {
    m_player = player;
}

void PlayerMovement::movePlayer(const char keyboardKey, const std::vector<Map *> &maps, const int currentLevel,
                                const std::function<void()> &nextLevel, const std::vector<Enemy *> &enemies) const {
    if (isBlockedByEnemy(enemies)) {
        return;
    }
    Map *map = maps[currentLevel];
    const Position nextPosition = calculateNextPosition(keyboardKey);

    if (nextPosition.x == m_player->getPosition().x && nextPosition.y == m_player->getPosition().y) {
        return;
    }

    const char nextTile = map->assignTilePosition(nextPosition);
    handleMovement(map, nextTile, nextPosition, nextLevel);
}

bool PlayerMovement::isBlockedByEnemy(const std::vector<Enemy *> &enemies) const {
    for (const Enemy *enemy: enemies) {
        if (enemy->isAggroed() &&
            Position::isInRangeOfOne(m_player->getPosition().x, m_player->getPosition().y,
                                     enemy->getPosition().x, enemy->getPosition().y)) {
            return true;
        }
    }
    return false;
}

Position PlayerMovement::calculateNextPosition(const char keyboardKey) const {
    Position nextPosition = m_player->getPosition();

    switch (keyboardKey) {
        case KEY_W:
            nextPosition.y -= 1;
            break;
        case KEY_S:
            nextPosition.y += 1;
            break;
        case KEY_A:
            nextPosition.x -= 1;
            break;
        case KEY_D:
            nextPosition.x += 1;
            break;
        default:
            break;
    }

    return nextPosition;
}

void PlayerMovement::handleMovement(Map *map, const char nextTile, const Position nextPosition,
                                    const std::function<void()> &nextLevel) const {
    if (nextTile == '.') {
        moveToPosition(map, nextPosition);
    } else if (nextTile == '|') {
        advanceToNextLevel(map, nextLevel);
    }
}

void PlayerMovement::moveToPosition(Map *map, const Position nextPosition) const {
    map->clearCharacterFromPosition(m_player->getPosition());
    m_player->setPosition(nextPosition);
    map->putCharacterInPosition(m_player->getPosition(), '@');
}

void PlayerMovement::advanceToNextLevel(Map *map, const std::function<void()> &nextLevel) const {
    nextLevel();
    map->clearCharacterFromPosition(m_player->getPosition());
}

