//
// Created by Lukyn on 14.12.2024.
//

#include "gargoilBuilder.h"

GargoilBuilder::GargoilBuilder() = default;

GargoilBuilder::~GargoilBuilder() {
    delete m_enemy;
}

void GargoilBuilder::createEnemy() {
    // m_enemy = new Enemy(EnemyType::gargoil, 20, 25, 200, 35, 20, {});
}
