//
// Created by ivo on 11/16/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "position.h"
#include "../value_objects/potion.h"
#include "../value_objects/role.h"
#include "../value_objects/screen.h"

class Player {
protected:
    int m_xp;
    int m_coins;
    Role m_role;
    int m_numberOfPotions;
    int m_hp;
    int m_damage;
    int m_armor;
    int m_range;
    Position m_playerPosition;

public:
    Player(Role role);

    void addPotion();

    void usePotion();

    int getHp() const;

    int getXp() const;

    int getNumberOfPotions() const;

    int getCoins() const;

    void movePlayer(char key, Screen currentScreen);

    void setPlayerPosition(Position playerPosition);

    Position getPlayerPosition() const;
};


#endif //PLAYER_H
