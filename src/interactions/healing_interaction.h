//
// Created by Lukyn on 16.01.2025.
//

#ifndef HEALING_INTERACTION_H
#define HEALING_INTERACTION_H

#include "interaction.h"
#include "../domain/entities/player.h"

class HealingInteraction final : public Interaction {
    char m_keyboardKey;

public:
    explicit HealingInteraction(char keyboardKey);

    void interaction(Player *player) override;
};

#endif //HEALING_INTERACTION_H
