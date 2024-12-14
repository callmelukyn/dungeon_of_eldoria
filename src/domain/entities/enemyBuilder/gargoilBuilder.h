//
// Created by Lukyn on 14.12.2024.
//

#ifndef GARGOILBUILDER_H
#define GARGOILBUILDER_H
#include "enemyBuilder.h"


class GargoilBuilder final : public EnemyBuilder {
public:
    GargoilBuilder();

    ~GargoilBuilder() override;

    void createEnemy() override;
};


#endif //GARGOILBUILDER_H
