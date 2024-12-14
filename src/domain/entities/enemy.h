//
// Created by Lukyn on 14.12.2024.
//

#ifndef ENEMY_H
#define ENEMY_H
#include "../../map/map.h"
#include "../value_objects/enemyType.h"

class Enemy {
    EnemyType m_enemyType;
    int m_hp;
    int m_damage;
    int m_coinReward;
    int m_xpReward;
    int m_potionDropChance;
    bool m_alive;
    Position m_enemyPosition;

public:
    Enemy(EnemyType enemyType, int hp, int damage, int coinReward, int xpReward, int potionDropChance);

    int getHp();

    int getDamage();

    int getXpReward();

    int getCoinReward();

    int getPotionDropChance();
};

#endif //ENEMY_H
