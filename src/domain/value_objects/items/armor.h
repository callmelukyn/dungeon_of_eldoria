//
// Created by Lukyn on 26.12.2024.
//

#ifndef ARMOR_H
#define ARMOR_H


class Armor {
    int m_armor;
    int m_price;
    int m_id;
    static int s_counter;

public:
    Armor(int armor, int price);

    int getArmor();

    int getPrice();

    int getId();
};


#endif //ARMOR_H
