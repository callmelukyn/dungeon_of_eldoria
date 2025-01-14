#ifndef COMBAT_H
#define COMBAT_H
#include "combat_state.h"
#include "../domain/entities/enemy.h"

class Player;

class Combat {
    CombatState *m_combatState;
    Enemy *m_enemy;
    Player *m_player;

public:
    Combat(bool isAggroed, Enemy *enemy, Player *player);

    void startCombat();

    void endCombat();

    bool isAggroed() const;
};


#endif //COMBAT_H
