#include "fight_state.h"

#include "combat.h"
#include "../tools/global_settings.h"

bool FightState::isAggroed() {
    return true;
}

void FightState::handleCombat(Combat *combat, const char keyboardKey) {
    if (keyboardKey == KEY_F) {
        combat->damageEnemy();
    }
    if (keyboardKey == KEY_F || keyboardKey == GlobalSettings::movementKeys(keyboardKey)) {
        combat->damagePlayer();
    }
}
