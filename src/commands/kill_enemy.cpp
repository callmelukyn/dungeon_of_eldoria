#include "kill_enemy.h"

KillEnemy::KillEnemy(Enemy *enemy, const std::vector<Map *> &maps, const int currentLevel) {
    enemy->setAggro(false);
    enemy->setAlive(false);
    maps[currentLevel]->clearCharacterFromPosition(enemy->getPosition());
    enemy->setPosition(Position{9999, 9999});
}
