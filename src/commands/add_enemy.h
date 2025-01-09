#ifndef ADD_ENEMY_H
#define ADD_ENEMY_H
#include "../domain/entities/enemy.h"


class AddEnemy {
    std::vector<Enemy *> m_enemies;
    std::vector<Map *> m_maps;

public:
    explicit AddEnemy(const std::vector<Map *> &maps);

    ~AddEnemy();

    void addMummy(int currentLevel, Position position);

    void addGhoul(int currentLevel, Position position);

    void addGargoyle(int currentLevel, Position position);

    void addBasilisk(int currentLevel, Position position);

    void addNecromancer(int currentLevel, Position position);

    std::vector<Enemy *> getEnemies();

    void clearEnemies();
};


#endif //ADD_ENEMY_H
