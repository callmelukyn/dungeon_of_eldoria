#ifndef LEVELS_H
#define LEVELS_H

#include <vector>
#include "map.h"
#include "../domain/entities/player.h"

class Levels {
    int m_currentLevel;
    std::vector<Map *> m_maps;

    void level0(Map *map) const;

    void level1(Map *map) const;

public:
    Levels();

    ~Levels();

    void loadAllLevels() const;

    void nextLevel(Player *player);

    void loadLevel(int level);

    std::vector<Map *> getMaps();

    int getCurrentLevel() const;
};


#endif //LEVELS_H
