#include "merchant_interaction.h"

MerchantInteraction::MerchantInteraction(const Screen currentScreen, Player *player, Merchant *merchant,
                                         const char keyboardKey,
                                         const std::function<void()> &changeScreen) {
    m_currentScreen = currentScreen;
    m_player = player;
    m_merchant = merchant;
    m_keyboardKey = keyboardKey;
    m_changeScreen = changeScreen;
}

void MerchantInteraction::interaction() const {
    if (Screen::game == m_currentScreen) {
        Position nextPosition = m_merchant->getPosition();

        const unsigned int distanceX = abs(static_cast<int>(m_player->getPlayerPosition().x - nextPosition.x));
        const unsigned int distanceY = abs(static_cast<int>(m_player->getPlayerPosition().y - nextPosition.y));

        if (distanceX <= 1 && distanceY <= 1 && m_keyboardKey == 'e') {
            m_changeScreen();
        }
    }
}
