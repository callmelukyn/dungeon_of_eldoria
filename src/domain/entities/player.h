//
// Created by ivo on 11/16/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <functional>
#include <vector>

#include "enemy.h"
#include "entity.h"
#include "../value_objects/items/potion.h"
#include "../value_objects/role.h"
#include "../value_objects/screen.h"
#include "../../map/map.h"

class Player : public Entity {
    int m_xp;
    int m_coins;
    Role m_role;
    int m_numberOfPotions;
    int m_armor;
    int m_range;

public:
    Player(Role role, int hp, int damage, int armor, int range, bool alive);

    void addPotion();

    void usePotion();

    int getHp() const;

    int getXp() const;

    int getDamage() const;

    Role getRole() const;

    int addXp(int xp);

    void addDamage(int damage);

    void addArmor(int armor);

    void addCoins(int coins);

    void removeCoins(int coins);

    int getNumberOfPotions() const;

    int getCoins() const;

    void movePlayer(char keyboardKey, Screen currentScreen, const std::vector<Map *> &maps, int currentLevel,
                    const std::function<void()> &nextLevel, const std::vector<Enemy *> &enemies);

    void setPlayerPosition(Position playerPosition);

    Position getPlayerPosition() const;
};


#endif //PLAYER_H
