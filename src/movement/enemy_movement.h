#ifndef ENEMY_MOVEMENT_H
#define ENEMY_MOVEMENT_H

#include "../domain/entities/enemy.h"
#include "../domain/entities/player.h"
#include "../map/position.h"

class EnemyMovement {
    Enemy *m_enemy;

    Position calculateNextPosition(const Player *player) const;

    bool canMoveToNextPosition(const Map *map, Position nextPosition);

    void updatePosition(Map *map, Position nextPosition) const;

public:
    explicit EnemyMovement(Enemy *enemy);

    void moveEnemy(const std::vector<Map *> &maps, int currentLevel,
                   const Player *player, char keyboardKey);
};

#endif //ENEMY_MOVEMENT_H
