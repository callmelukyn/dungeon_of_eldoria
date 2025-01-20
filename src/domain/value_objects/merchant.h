//
// Created by Lukyn on 14.12.2024.
//

#ifndef MERCHANT_H
#define MERCHANT_H
#include "../../map/position.h"

class Merchant {
    Position m_position;

public:
    explicit Merchant(Position position);

    Position getPosition() const;

    bool isAnyMerchantInRange(Position playerPosition) const;
};


#endif //MERCHANT_H
