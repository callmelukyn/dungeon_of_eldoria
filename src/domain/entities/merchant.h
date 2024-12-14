//
// Created by Lukyn on 14.12.2024.
//

#ifndef MERCHANT_H
#define MERCHANT_H
#include "../../map/map.h"

class Merchant {
    Position m_position;

public:
    Merchant(Position position);

    Position getPosition();

    void displayShop() const;
};


#endif //MERCHANT_H
