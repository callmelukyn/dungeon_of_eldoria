#ifndef PASSIVE_STATE_H
#define PASSIVE_STATE_H
#include "combat_state.h"


class PassiveState : public CombatState {
public:
    bool isAggroed() override;
};


#endif //PASSIVE_STATE_H
