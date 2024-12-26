//
// Created by Lukyn on 26.12.2024.
//

#ifndef WEAPON_H
#define WEAPON_H


class Weapon {
    int m_damage;
    int m_price;

public:
    Weapon(int damage, int price);

    int getDamage();

    int getPrice();
};


#endif //WEAPON_H
