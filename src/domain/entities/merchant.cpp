//
// Created by Lukyn on 14.12.2024.
//

#include "merchant.h"

Merchant::Merchant(Position position) {
    m_position = position;
}

Position Merchant::getPosition() {
    return m_position;
}
