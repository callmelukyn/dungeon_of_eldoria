//
// Created by Lukyn on 14.12.2024.
//

#ifndef GHOULBUILDER_H
#define GHOULBUILDER_H
#include "enemyBuilder.h"


class GhoulBuilder final : public EnemyBuilder {
public:
    GhoulBuilder();

    ~GhoulBuilder() override;

    void createEnemy() override;
};


#endif //GHOULBUILDER_H
