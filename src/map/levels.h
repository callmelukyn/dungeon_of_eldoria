#ifndef LEVELS_H
#define LEVELS_H

#include <vector>
#include "map.h"
#include "../commands/add_enemy.h"
#include "../commands/add_merchant.h"
#include "../commands/add_prisoner.h"

class Levels {
    int m_currentLevel;
    std::vector<Map *> m_maps;
    AddEnemy *m_addEnemy;
    AddMerchant *m_addMerchant;
    AddPrisoner *m_addPrisoner;

    void clearCharactersFromPreviousLevel() const;

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

    AddMerchant *getMerchant() const;

    AddPrisoner *getPrisoner() const;
};


#endif //LEVELS_H
