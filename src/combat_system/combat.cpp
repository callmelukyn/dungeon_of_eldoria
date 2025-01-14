#include "combat.h"

#include "fight_state.h"
#include "passive_state.h"

Combat::Combat(const bool isAggroed, Enemy *enemy, Player *player) {
    if (isAggroed) {
        m_combatState = new FightState();
    } else {
        m_combatState = new PassiveState();
    }
}

void Combat::startCombat() {
    delete m_combatState;
    m_combatState = new FightState();
    m_enemy->setAggro(m_combatState->isAggroed());
}

void Combat::endCombat() {
    delete m_combatState;
    m_combatState = new PassiveState();
    m_enemy->setAggro(m_combatState->isAggroed());
}

bool Combat::isAggroed() const {
    return m_combatState->isAggroed();
}
