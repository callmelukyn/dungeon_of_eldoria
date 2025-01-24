#include "passive_state.h"

#include "combat.h"
#include "../tools/global_settings.h"

bool PassiveState::isAggroed() {
    return false;
}

void PassiveState::handleCombat(Combat *combat, const char keyboardKey) {
    if (combat->isPlayerInRange() && keyboardKey == KEY_F) {
        combat->damageEnemy();
    }
}
