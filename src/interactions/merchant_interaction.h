#ifndef MERCHANT_INTERACTION_H
#define MERCHANT_INTERACTION_H

#include "../domain/value_objects/merchant.h"
#include "../domain/entities/player.h"
#include "../domain/value_objects/screen.h"


class MerchantInteraction {
    Screen m_currentScreen;
    Player *m_player;
    Merchant *m_merchant;
    char m_keyboardKey;
    std::function<void()> m_changeScreen;

public:
    MerchantInteraction(Screen currentScreen, Player *player, Merchant *merchant, char keyboardKey,
                        const std::function<void()> &changeScreen);

    void interaction() const;
};


#endif //MERCHANT_INTERACTION_H
