//
// Created by Lukyn on 14.12.2024.
//

#ifndef ENEMY_H
#define ENEMY_H
#include "player.h"
#include "../../map/map.h"
#include "../value_objects/enemyType.h"
#include "../value_objects/screen.h"

class Enemy : public Entity {
protected:
    EnemyType m_enemyType;
    int m_coinReward;
    int m_xpReward;
    int m_potionDropChance;
    int m_range;
    static bool m_aggroed;

public:
    Enemy(EnemyType enemyType, int hp, int damage, int coinReward, int xpReward, int potionDropChance,
          int range, bool alive, Position enemyPosition);

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
