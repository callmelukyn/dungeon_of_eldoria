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
#include "../value_objects/items/weapon.h"
#include "../value_objects/items/armor.h"
#include "../value_objects/role.h"
#include "../value_objects/screen.h"
#include "../../map/map.h"

class Player : public Entity {
    std::vector<Weapon *> m_weapons;
    std::vector<Armor *> m_armors;
    int m_xp;
    int m_maxHp; //MAX HP you can achieve by healing. It increases with LVL Ups - but not your current HP.
    int m_level; //XP Level
    int m_coins;
    Role m_role;
    int m_numberOfPotions;
    int m_armor;
    int m_range;

public:
    Player(Role role, int hp, int damage, int armor, int range, bool alive);

    void checkLevelStatus();

    void levelUp();

    void addPotion();

    void usePotion(Potion *potion);

    int getHp() const;

    int getXp() const;

    int getLevel() const; //XP Level

    int getDamage() const;

    int getTotalDefense(); //Methods for fighting

    int getTotalDamage(); //Methods for fighting

    Role getRole() const;

    void addWeapon(Weapon *weapon);

    void addArmor(Armor *armor);

    void addXp(int xp);

    void addHp(int hp);

    void addMaxHp(int maxHp);

    void addDamage(int damage);

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
