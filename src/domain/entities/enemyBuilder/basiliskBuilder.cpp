//
// Created by Lukyn on 14.12.2024.
//

#include "basiliskBuilder.h"

BasiliskBuilder::BasiliskBuilder() = default;

BasiliskBuilder::~BasiliskBuilder() {
    delete m_enemy;
}

void BasiliskBuilder::createEnemy() {
    m_enemy = new Enemy(EnemyType::basilisk, 50, 45, 500, 80, 40);
}
