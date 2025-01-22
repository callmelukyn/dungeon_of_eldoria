//
// Created by Lukyn on 16.01.2025.
//

#include "healing_interaction.h"

HealingInteraction::HealingInteraction(const char keyboardKey) {
    m_keyboardKey = keyboardKey;
}

void HealingInteraction::interaction(Player *player) {
    if (m_keyboardKey == 'h' || m_keyboardKey == 'H') {
        player->usePotion();
    }
}
