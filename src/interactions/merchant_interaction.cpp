#include "merchant_interaction.h"

MerchantInteraction::MerchantInteraction(Merchant *merchant,
                                         const char keyboardKey,
                                         const std::function<void()> &changeScreen) {
    m_merchant = merchant;
    m_keyboardKey = keyboardKey;
    m_changeScreen = changeScreen;
}

void MerchantInteraction::interaction(Player *player) {
    if (m_merchant == nullptr) {
        return;
    }
    // Check if player is in range of 1 of merchant.
    if (Position::isInRangeOfOne(player->getPosition().x,
                                 player->getPosition().y,
                                 m_merchant->getPosition().x,
                                 m_merchant->getPosition().y) &&
        m_keyboardKey == 'e' || m_keyboardKey == 'E') {
        m_changeScreen();
    }
}
