//
// Created by Lukyn on 14.12.2024.
//

#include "mummyBuilder.h"

MummyBuilder::MummyBuilder() = default;

MummyBuilder::~MummyBuilder() {
    delete m_enemy;
}

void MummyBuilder::createEnemy() {
    // m_enemy = new Enemy(EnemyType::mummy, 10, 10, 100, 20, 10);
}
