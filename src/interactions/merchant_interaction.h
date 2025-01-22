#ifndef MERCHANT_INTERACTION_H
#define MERCHANT_INTERACTION_H

#include <functional>

#include "interaction.h"
#include "../domain/entities/player.h"
#include "../domain/value_objects/merchant.h"

class MerchantInteraction final : public Interaction {
    Merchant *m_merchant;
    char m_keyboardKey;
    std::function<void()> m_changeScreen;

public:
    MerchantInteraction(Merchant *merchant, char keyboardKey,
                        const std::function<void()> &changeScreen);

    void interaction(Player *player) override;
};

#endif //MERCHANT_INTERACTION_H
