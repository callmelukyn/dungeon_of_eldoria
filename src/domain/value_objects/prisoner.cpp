//
// Created by Lukyn on 14.12.2024.
//

#include "prisoner.h"

Prisoner::Prisoner(const Position position) : m_position(position) {
}

Position Prisoner::getPosition() const {
    return m_position;
}

void Prisoner::setPosition(const Position position) {
    m_position = position;
}
