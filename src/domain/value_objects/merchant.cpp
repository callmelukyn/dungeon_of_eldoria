//
// Created by Lukyn on 14.12.2024.
//

#include "merchant.h"

Merchant::Merchant(const Position position): m_position(position) {
}

Position Merchant::getPosition() const {
    return m_position;
}
