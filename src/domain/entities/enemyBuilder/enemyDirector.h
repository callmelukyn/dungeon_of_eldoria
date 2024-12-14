//
// Created by Lukyn on 14.12.2024.
//

#ifndef ENEMYDIRECTOR_H
#define ENEMYDIRECTOR_H
#include "enemyBuilder.h"


class EnemyDirector {
    EnemyBuilder *m_builder;

public:
    explicit EnemyDirector(EnemyBuilder *builder);

    void setBuilder(EnemyBuilder *builder);

    Enemy *createEnemy() const;
};


#endif //ENEMYDIRECTOR_H
