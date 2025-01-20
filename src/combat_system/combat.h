#ifndef COMBAT_H
#define COMBAT_H
#include "combat_state.h"
#include "../domain/entities/enemy.h"

class Combat {
    CombatState *m_combatState;
    Enemy *m_enemy;
    Player *m_player;
    static bool s_startedCombat;

    void setState(CombatState *newState);

    void update();

public:
    Combat(Enemy *enemy, Player *player);

    ~Combat();

    void startCombat();

    void endCombat();

    void damageEnemy() const;

    void damagePlayer() const;

    void handleCombat(char keyboardKey);

    bool isPlayerInRange() const;

    static bool didStartCombat();
};

#endif //COMBAT_H
