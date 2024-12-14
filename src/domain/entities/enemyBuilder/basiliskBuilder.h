//
// Created by Lukyn on 14.12.2024.
//

#ifndef BASILISKBUILDER_H
#define BASILISKBUILDER_H
#include "enemyBuilder.h"


class BasiliskBuilder final : public EnemyBuilder {
public:
    BasiliskBuilder();

    ~BasiliskBuilder() override;

    void createEnemy() override;
};


#endif //BASILISKBUILDER_H
