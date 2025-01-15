#ifndef COMBAT_H
#define COMBAT_H
#include "combat_state.h"
#include "../domain/entities/enemy.h"

class Player;

class Combat {
    CombatState *m_combatState;
    Enemy *m_enemy;
    Player *m_player;

    void setState(CombatState *newState);

    void update();

public:
    Combat(Enemy *enemy, Player *player);

    void startCombat();

    void endCombat();

    void damageEnemy() const;

    void damagePlayer() const;

    void handleCombat(char keyboardKey);

    bool isPlayerInRange() const;
};

#endif //COMBAT_H
