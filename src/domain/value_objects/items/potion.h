//
// Created by Lukyn on 26.12.2024.
//

#ifndef POTION_H
#define POTION_H


class Potion {
    int m_hpGain;
    int m_price;

public:
    Potion();

    int getHpGain() const;

    int getPrice() const;
};


#endif //POTION_H
