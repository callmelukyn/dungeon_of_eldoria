//
// Created by Lukyn on 14.12.2024.
//

#ifndef MUMMYBUILDER_H
#define MUMMYBUILDER_H
#include "enemyBuilder.h"

class MummyBuilder final : public EnemyBuilder {
public:
    MummyBuilder();

    ~MummyBuilder() override;

    void createEnemy() override;
};


#endif //MUMMYBUILDER_H
