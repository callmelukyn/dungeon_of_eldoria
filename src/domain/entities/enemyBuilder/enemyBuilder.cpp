//
// Created by Lukyn on 14.12.2024.
//

#include "enemyBuilder.h"

EnemyBuilder::EnemyBuilder() {
    m_enemy = nullptr;
}

Enemy *EnemyBuilder::getEnemy() const {
    return m_enemy;
}
