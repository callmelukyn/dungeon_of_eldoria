#ifndef FIGHT_STATE_H
#define FIGHT_STATE_H
#include "combat_state.h"


class FightState : public CombatState {
public:
    bool isAggroed() override;
};


#endif //FIGHT_STATE_H
