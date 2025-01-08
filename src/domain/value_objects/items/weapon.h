//
// Created by Lukyn on 26.12.2024.
//

#ifndef WEAPON_H
#define WEAPON_H


class Weapon {
    int m_damage;
    int m_price;
    int m_id;
    static int s_counter;

public:
    Weapon(int damage, int price);

    int getDamage();

    int getPrice();

    int getId();
};


#endif //WEAPON_H
