//
// Created by Lukyn on 16.01.2025.
//

#include "prisoner_interaction.h"

PrisonerInteraction::PrisonerInteraction(Prisoner *prisoner, const char keyboardKey,
                                         const std::vector<Map *> &maps, const int currentLevel) {
    m_prisoner = prisoner;
    m_keyboardKey = keyboardKey;
    m_maps = maps;
    m_currentLevel = currentLevel;
}

void PrisonerInteraction::interaction(Player *player) {
    // Check if player is in range of 1 of prisoner.
    if (Position::isInRangeOfOne(player->getPosition().x,
                                 player->getPosition().y,
                                 m_prisoner->getPosition().x,
                                 m_prisoner->getPosition().y) &&
        m_keyboardKey == 'e' || m_keyboardKey == 'E') {
        m_prisoner->rescuePrisoner(player, m_maps, m_currentLevel);
    }
}
