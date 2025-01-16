#include "fight_state.h"

#include <iostream>

#include "combat.h"
#include "../tools/global_settings.h"

bool FightState::isAggroed() {
    //Nekam se bude muset pridat nejspis clearScreen aby se to dokazalo smazat cely pri zmene stavu, ted se prepisuje jen horni radek
    GlobalSettings::setColor(COLOR_RED);
    std::cout << "---------------\n";
    std::cout << "  IN COMBAT\n";
    std::cout << "---------------\n";
    GlobalSettings::setColor(COLOR_DEFAULT);
    return true;
}

void FightState::handleCombat(Combat *combat, const char keyboardKey) {
    if (keyboardKey == 'f' || keyboardKey == 'F') {
        combat->damageEnemy();
    }
    if (keyboardKey == 'f' || keyboardKey == 'F' || keyboardKey == GlobalSettings::movementKeys(keyboardKey)) {
        combat->damagePlayer();
    }
}
