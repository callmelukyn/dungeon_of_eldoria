//
// Created by Lukyn on 16.01.2025.
//

#include "healing_interaction.h"

HealingInteraction::HealingInteraction(Player *player, char keyboardKey) {
    m_player = player;
    m_keyboardKey = keyboardKey;
}

void HealingInteraction::interaction() const {
    if (m_keyboardKey == 'h' || m_keyboardKey == 'H') {
        m_player->usePotion();
    }
}
