#ifndef COMBAT_STATE_H
#define COMBAT_STATE_H


class CombatState {
public:
    virtual ~CombatState() = default;

    virtual bool isAggroed() = 0;
};


#endif //COMBAT_STATE_H
