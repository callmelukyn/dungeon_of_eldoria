//
// Created by Lukyn on 16.01.2025.
//

#ifndef HEALING_INTERACTION_H
#define HEALING_INTERACTION_H

#include "../domain/entities/player.h"

class HealingInteraction {
    Player *m_player;
    char m_keyboardKey;

public:
    HealingInteraction(Player *player, char keyboardKey);

    void interaction() const;
};


#endif //HEALING_INTERACTION_H
