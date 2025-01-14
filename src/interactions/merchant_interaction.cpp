#include "merchant_interaction.h"

MerchantInteraction::MerchantInteraction(Player *player, Merchant *merchant,
                                         const char keyboardKey,
                                         const std::function<void()> &changeScreen) {
    m_player = player;
    m_merchant = merchant;
    m_keyboardKey = keyboardKey;
    m_changeScreen = changeScreen;
}

void MerchantInteraction::interaction() const {
    // Check if player is in range of 1 of merchant.
    if (Position::getDistanceX(m_player->getPosition().x, m_merchant->getPosition().x) <= 1 &&
        Position::getDistanceY(m_player->getPosition().y, m_merchant->getPosition().y) <= 1 &&
        m_keyboardKey == 'e') {
        m_changeScreen();
    }
}
