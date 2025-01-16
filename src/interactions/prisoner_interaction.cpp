//
// Created by Lukyn on 16.01.2025.
//

#include "prisoner_interaction.h"

PrisonerInteraction::PrisonerInteraction(Player *player, Prisoner *prisoner, char keyboardKey) {
    m_player = player;
    m_prisoner = prisoner;
    m_keyboardKey = keyboardKey;
}


void PrisonerInteraction::interaction(const std::vector<Map *> &maps, const int currentLevel) const {
    // Check if player is in range of 1 of prisoner.
    if (Position::isInRangeOfOne(m_player->getPosition().x,
                                 m_player->getPosition().y,
                                 m_prisoner->getPosition().x,
                                 m_prisoner->getPosition().y) &&
        m_keyboardKey == 'e' || m_keyboardKey == 'E') {
        m_prisoner->rescuePrisoner(m_player, maps, currentLevel);
    }
}
