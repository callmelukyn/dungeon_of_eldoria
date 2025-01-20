#include "combat.h"

#include "fight_state.h"
#include "passive_state.h"
#include "../domain/entities/player.h"
#include "../tools/global_settings.h"

bool Combat::s_startedCombat = false;

Combat::Combat(Enemy *enemy, Player *player) {
    m_enemy = enemy;
    m_player = player;
    m_combatState = new PassiveState();
}

Combat::~Combat() {
    delete m_combatState;
}

void Combat::setState(CombatState *newState) {
    delete m_combatState;
    m_combatState = newState;
}

void Combat::startCombat() {
    setState(new FightState());
    if (!s_startedCombat) {
        s_startedCombat = true;
        GlobalSettings::setColor(COLOR_RED);
        std::cout << "\r---------------\n";
        std::cout << "\r  IN COMBAT\n";
        std::cout << "\r---------------\n";
        GlobalSettings::setColor(COLOR_DEFAULT);
    }
    m_enemy->setAggro(m_combatState->isAggroed());
}

void Combat::endCombat() {
    setState(new PassiveState());
    s_startedCombat = false;
    std::cout << "\r                           \n";
    std::cout << "\r                           \n";
    std::cout << "\r                           \r";
    m_enemy->setAggro(m_combatState->isAggroed());
}

void Combat::update() {
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
        m_player->takeDamage(m_enemy->getDamage());
    }
}

void Combat::handleCombat(const char keyboardKey) {
    update();
    m_combatState->handleCombat(this, keyboardKey);
}

bool Combat::isPlayerInRange() const {
    return m_player->isInRange(m_player->getPosition(), m_enemy->getPosition());
}

bool Combat::didStartCombat() {
    return s_startedCombat;
}
