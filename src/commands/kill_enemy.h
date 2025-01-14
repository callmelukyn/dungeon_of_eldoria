#ifndef KILL_ENEMY_H
#define KILL_ENEMY_H
#include "../domain/entities/enemy.h"


class KillEnemy {
public:
    KillEnemy(Enemy *enemy, const std::vector<Map *> &maps, int currentLevel);
};


#endif //KILL_ENEMY_H
