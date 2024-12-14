//
// Created by Lukyn on 14.12.2024.
//

#ifndef NECROMANCERBUILDER_H
#define NECROMANCERBUILDER_H
#include "enemyBuilder.h"


class NecromancerBuilder final : public EnemyBuilder {
public:
    NecromancerBuilder();

    ~NecromancerBuilder() override;

    void createEnemy() override;
};


#endif //NECROMANCERBUILDER_H
