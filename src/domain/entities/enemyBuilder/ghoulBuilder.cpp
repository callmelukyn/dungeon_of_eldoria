//
// Created by Lukyn on 14.12.2024.
//

#include "ghoulBuilder.h"

GhoulBuilder::GhoulBuilder() = default;

GhoulBuilder::~GhoulBuilder() {
    delete m_enemy;
}

void GhoulBuilder::createEnemy() {
    // m_enemy = new Enemy(EnemyType::ghoul, 35, 30, 300, 55, 25);
}
