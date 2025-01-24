#ifndef COMBAT_H
#define COMBAT_H
#include "combat_state.h"
#include "../domain/entities/enemy.h"

class Combat {
    CombatState *m_combatState;
    Enemy *m_enemy;
    Player *m_player;
    static bool s_startedCombat;
    int m_randomDamage;

    void setState(CombatState *newState);

    void update(char keyboardKey);

    void startCombat(char keyboardKey);

    void endCombat();

    void displayCombatHeader();

    void handleCombatAttack() const;

public:
    Combat(Enemy *enemy, Player *player);

    ~Combat();

    void damageEnemy() const;

    void damagePlayer() const;

    void handleCombat(char keyboardKey);

    bool isPlayerInRange() const;
};

#endif //COMBAT_H
