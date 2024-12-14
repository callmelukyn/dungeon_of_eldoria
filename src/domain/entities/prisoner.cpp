//
// Created by Lukyn on 14.12.2024.
//

#include "prisoner.h"


Prisoner::Prisoner(Position position) {
    m_position = position;
}

Position Prisoner::getPosition() {
    return m_position;
}

void Prisoner::rescuePrisoner(Player *player) {
    player->addXp(30);
    player->addCoins(200);
}
