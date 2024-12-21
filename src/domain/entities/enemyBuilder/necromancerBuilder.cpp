//
// Created by Lukyn on 14.12.2024.
//

#include "necromancerBuilder.h"

NecromancerBuilder::NecromancerBuilder() = default;

NecromancerBuilder::~NecromancerBuilder() {
    delete m_enemy;
}

void NecromancerBuilder::createEnemy() {
    // m_enemy = new Enemy(EnemyType::necromancer, 200, 50, 0, 0, 0);
}
