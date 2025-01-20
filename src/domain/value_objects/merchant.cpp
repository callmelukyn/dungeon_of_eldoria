//
// Created by Lukyn on 14.12.2024.
//

#include "merchant.h"

Merchant::Merchant(const Position position): m_position(position) {
}

Position Merchant::getPosition() const {
    return m_position;
}

bool Merchant::isAnyMerchantInRange(const Position playerPosition) const {
    bool isMerchantInRange = false;
    if (Position::isInRangeOfOne(playerPosition.x, playerPosition.y,
                                 m_position.x, m_position.y)) {
        isMerchantInRange = true;
    }
    return isMerchantInRange;
}
