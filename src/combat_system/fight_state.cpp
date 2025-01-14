#include "fight_state.h"

#include <iostream>

bool FightState::isAggroed() {
    std::cout << "IN COMBAT";
    return true;
}
