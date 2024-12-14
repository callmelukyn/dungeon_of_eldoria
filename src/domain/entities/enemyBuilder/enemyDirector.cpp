//
// Created by Lukyn on 14.12.2024.
//

#include "enemyDirector.h"

EnemyDirector::EnemyDirector(EnemyBuilder *builder) {
    m_builder = builder;
}

void EnemyDirector::setBuilder(EnemyBuilder *builder) {
    m_builder = builder;
}

Enemy *EnemyDirector::createEnemy() const {
    m_builder->createEnemy();
    return m_builder->getEnemy();
}
