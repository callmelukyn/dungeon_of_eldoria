//
// Created by Lukyn on 14.12.2024.
//

#ifndef ENEMY_H
#define ENEMY_H
#include "entity.h"
#include "../../map/map.h"
#include "../value_objects/enemy_type.h"
#include "../value_objects/screen.h"

class Player;

class Enemy : public Entity {
protected:
    EnemyType m_enemyType;
    int m_coinReward;
    int m_xpReward;
    int m_potionDropChance;
    int m_range;
    bool m_aggroed;

public:
    Enemy(EnemyType enemyType, int hp, int damage, int coinReward, int xpReward, int potionDropChance,
          int range, Position enemyPosition);

    int getHp() const;

    int getDamage() const;

    int getXpReward() const;

    int getCoinReward() const;

    int getPotionDropChance() const;

    void moveEnemy(Screen currentScreen, const std::vector<Map *> &maps, int currentLevel, const Player *player,
                   char keyboardKey);

    Position getEnemyPosition() const;

    bool isAggroed() const;
};

#endif //ENEMY_H
