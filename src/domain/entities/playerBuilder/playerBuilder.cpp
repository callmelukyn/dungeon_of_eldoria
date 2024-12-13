#include "playerBuilder.h"

PlayerBuilder::PlayerBuilder() {
    m_player = nullptr;
}

Player *PlayerBuilder::getPlayer() const {
    return m_player;
}
