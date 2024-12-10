//
// Created by ivo on 11/16/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <functional>
#include <vector>

#include "../value_objects/potion.h"
#include "../value_objects/role.h"
#include "../value_objects/screen.h"
#include "../../map/map.h"

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

    void movePlayer(char keyboardKey, Screen currentScreen, const std::vector<Map *> &maps, int currentLevel,
                    const std::function<void()> &nextLevel);

    void setPlayerPosition(Position playerPosition);

    Position getPlayerPosition() const;
};


#endif //PLAYER_H
