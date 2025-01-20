#include "passive_state.h"

#include "combat.h"

bool PassiveState::isAggroed() {
    return false;
}

void PassiveState::handleCombat(Combat *combat, const char keyboardKey) {
    if (keyboardKey == 'f' || keyboardKey == 'F') {
        if (combat->isPlayerInRange()) {
            if (!Combat::didStartCombat()) {
                // If in range and player attacks, start combat and deal damage
                combat->startCombat();
                combat->damageEnemy();
            } else {
                combat->damageEnemy();
            }
        }
    }
}
