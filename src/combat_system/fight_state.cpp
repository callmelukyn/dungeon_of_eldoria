#include "fight_state.h"

#include <iostream>

#include "combat.h"
#include "../tools/global_settings.h"

bool FightState::isAggroed() {
    std::cout << "IN COMBAT";
    return true;
}

void FightState::handleCombat(Combat *combat, const char keyboardKey) {
    if (keyboardKey == 'f') {
        combat->damageEnemy();
    }
    if (keyboardKey == 'f' || keyboardKey == GlobalSettings::movementKeys(keyboardKey)) {
        combat->damagePlayer();
    }
}
