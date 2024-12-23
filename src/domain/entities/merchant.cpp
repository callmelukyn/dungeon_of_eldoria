//
// Created by Lukyn on 14.12.2024.
//

#include "merchant.h"

Merchant::Merchant(Position position): m_position(position) {
    m_range = 1;
}

Position Merchant::getPosition() {
    return m_position;
}

// Make class
void Merchant::interaction(const Screen currentScreen, const Player *player, const char keyboardKey,
                           const std::function<void()> &changeScreen) const {
    if (Screen::game == currentScreen) {
        Position nextPosition = m_position;

        const unsigned int distanceX = abs(static_cast<int>(player->getPlayerPosition().x - nextPosition.x));
        const unsigned int distanceY = abs(static_cast<int>(player->getPlayerPosition().y - nextPosition.y));

        if (distanceX <= m_range && distanceY <= m_range && keyboardKey == 'e') {
            changeScreen();
        }
    }
}
