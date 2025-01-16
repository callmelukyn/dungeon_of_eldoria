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
    if (Position::isInRangeOfOne(m_player->getPosition().x,
                                 m_player->getPosition().y,
                                 m_merchant->getPosition().x,
                                 m_merchant->getPosition().y) &&
        m_keyboardKey == 'e' || m_keyboardKey == 'E') {
        m_changeScreen();
    }
}
