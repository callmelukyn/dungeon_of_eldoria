#ifndef LEVELS_H
#define LEVELS_H

#include <vector>
#include "map.h"
#include "../domain/entities/player.h"
#include "../commands/add_enemy.h"

class Levels {
    int m_currentLevel;
    std::vector<Map *> m_maps;
    AddEnemy *m_addEnemy;

    void level0() const;

    void level1() const;

    void level2() const;

    void level3() const;

    void level4() const;

    void level5() const;

public:
    Levels();

    ~Levels();

    void loadAllLevels() const;

    void renderCurrentLevel() const;

    void nextLevel(Player *player);

    std::vector<Map *> getMaps();

    int getCurrentLevel() const;

    AddEnemy *getEnemy() const;
};


#endif //LEVELS_H
