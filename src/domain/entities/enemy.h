//
// Created by Lukyn on 14.12.2024.
//

#ifndef ENEMY_H
#define ENEMY_H
#include "player.h"
#include "../../map/map.h"
#include "../value_objects/enemyType.h"
#include "../value_objects/screen.h"

class Enemy {
protected:
    EnemyType m_enemyType;
    int m_hp;
    int m_damage;
    int m_coinReward;
    int m_xpReward;
    int m_potionDropChance;
    int m_range;
    bool m_alive;
    static bool m_aggroed;
    Position m_enemyPosition;

public:
    Enemy(EnemyType enemyType, int hp, int damage, int coinReward, int xpReward, int potionDropChance,
          int range, Position enemyPosition);

    int getHp();

    int getDamage();

    int getXpReward();

    int getCoinReward();

    int getPotionDropChance();

    bool getAggroed() const;

    void moveEnemy(Screen currentScreen, const std::vector<Map *> &maps, int currentLevel, const Player *player,
                   char keyboardKey);

    Position getEnemyPosition();

    static bool isAggroed();
};

#endif //ENEMY_H
