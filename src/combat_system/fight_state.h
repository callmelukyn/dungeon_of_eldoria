#ifndef FIGHT_STATE_H
#define FIGHT_STATE_H
#include "combat_state.h"

class FightState final : public CombatState {
public:
    bool isAggroed() override;

    void handleCombat(Combat *combat, char keyboardKey) override;
};

#endif //FIGHT_STATE_H
