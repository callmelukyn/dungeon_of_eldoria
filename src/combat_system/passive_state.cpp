#include "passive_state.h"

#include <iostream>

#include "combat.h"
#include "../tools/global_settings.h"

bool PassiveState::isAggroed() {
    std::cout << "\b                       \r";
    return false;
}

void PassiveState::handleCombat(Combat *combat, const char keyboardKey) {
    if (keyboardKey == 'f' || keyboardKey == 'F') {
        if (combat->isPlayerInRange()) {
            // If in range and player attacks, start combat and deal damage
            combat->startCombat();
            combat->damageEnemy();
        } else {
            std::cout << "No enemies in range\r";
        }
    }
}
