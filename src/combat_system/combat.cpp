#include "combat.h"

#include "fight_state.h"
#include "passive_state.h"
#include "../domain/entities/player.h"

Combat::Combat(Enemy *enemy, Player *player) {
    m_enemy = enemy;
    m_player = player;
    m_combatState = new PassiveState();
}

void Combat::setState(CombatState *newState) {
    delete m_combatState;
    m_combatState = newState;
}

void Combat::startCombat() {
    setState(new FightState());
    m_enemy->setAggro(m_combatState->isAggroed());
}

void Combat::endCombat() {
    setState(new PassiveState());
    m_enemy->setAggro(m_combatState->isAggroed());
}

void Combat::update() {
    // Check if player walked into range
    if (!m_combatState->isAggroed() && m_enemy->isInRange(m_player->getPosition(), m_enemy->getPosition())) {
        startCombat();
    }

    if (!m_enemy->isAggroed() && !m_enemy->isAlive()) {
        endCombat();
    }
}

void Combat::damageEnemy() const {
    if (m_player->isInRange(m_player->getPosition(), m_enemy->getPosition())) {
        m_enemy->takeDamage(m_player->getDamage());
    }
}

void Combat::damagePlayer() const {
    if (Position::isInRangeOfOne(m_player->getPosition().x, m_player->getPosition().y,
                                 m_enemy->getPosition().x, m_enemy->getPosition().y)) {
        m_player->takeDamage(m_player->getDamage());
    }
}

void Combat::handleCombat(const char keyboardKey) {
    update();
    m_combatState->handleCombat(this, keyboardKey);
}

bool Combat::isPlayerInRange() const {
    return m_player->isInRange(m_player->getPosition(), m_enemy->getPosition());
}
