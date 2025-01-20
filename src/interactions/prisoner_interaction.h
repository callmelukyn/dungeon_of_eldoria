//
// Created by Lukyn on 16.01.2025.
//

#ifndef PRISONER_INTERACTION_H
#define PRISONER_INTERACTION_H

#include "../domain/entities/player.h"
#include "../domain/value_objects/prisoner.h"

class PrisonerInteraction {
    Player *m_player;
    Prisoner *m_prisoner;
    char m_keyboardKey;

public:
    PrisonerInteraction(Player *player, Prisoner *prisoner, char keyboardKey);

    void interaction(const std::vector<Map *> &maps, int currentLevel) const;
};

#endif //PRISONER_INTERACTION_H
