//
// Created by Lukyn on 16.01.2025.
//

#ifndef PRISONER_INTERACTION_H
#define PRISONER_INTERACTION_H

#include "interaction.h"
#include "../domain/entities/player.h"
#include "../domain/value_objects/prisoner.h"

class PrisonerInteraction final : public Interaction {
    Prisoner *m_prisoner;
    char m_keyboardKey;
    std::vector<Map *> m_maps;
    int m_currentLevel;

public:
    PrisonerInteraction(Prisoner *prisoner, char keyboardKey, const std::vector<Map *> &maps,
                        int currentLevel);

    void interaction(Player *player) override;
};

#endif //PRISONER_INTERACTION_H
