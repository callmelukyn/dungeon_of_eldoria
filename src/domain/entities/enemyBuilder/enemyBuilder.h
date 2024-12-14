//
// Created by Lukyn on 14.12.2024.
//

#ifndef ENEMYBUILDER_H
#define ENEMYBUILDER_H
#include "../enemy.h"


class EnemyBuilder {
protected:
    Enemy *m_enemy;

public:
    EnemyBuilder();

    virtual ~EnemyBuilder() = default;

    virtual void createEnemy() = 0;

    Enemy *getEnemy() const;
};


#endif //ENEMYBUILDER_H
