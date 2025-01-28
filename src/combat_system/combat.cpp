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
    m_randomDamage = m_enemy->randomDamage();
}

Combat::~Combat() {
    delete m_combatState;
}

void Combat::setState(CombatState *newState) {
    delete m_combatState;
    m_combatState = newState;
}

void Combat::startCombat(const char keyboardKey) {
    setState(new FightState());
    if (!s_startedCombat) {
        s_startedCombat = true;
        displayCombatHeader();
    }
    if (keyboardKey == KEY_F) {
        handleCombatAttack();
    }
    m_enemy->setAggro(m_combatState->isAggroed());
}

void Combat::endCombat() {
    setState(new PassiveState());
    s_startedCombat = false;
    std::cout << "\r                                              \r";
    m_enemy->setAggro(m_combatState->isAggroed());
}

void Combat::update(const char keyboardKey) {
    if ((isPlayerInRange() && keyboardKey == KEY_F) || m_enemy->isInRange(
            m_player->getPosition(), m_enemy->getPosition())) {
        startCombat(keyboardKey);
    }

    if (!m_enemy->isAggroed() && !m_enemy->isAlive()) {
        endCombat();
    }
}

void Combat::damageEnemy() const {
    if (m_player->isInRange(m_player->getPosition(), m_enemy->getPosition())) {
        m_enemy->takeDamage(m_player->getTotalDamage());
    }
}

void Combat::damagePlayer() const {
    if (Position::isInRangeOfOne(m_player->getPosition().x, m_player->getPosition().y,
                                 m_enemy->getPosition().x, m_enemy->getPosition().y)) {
        if (m_player->getTotalDefense() - m_enemy->getDamage() < 0) {
            m_player->takeDamage(m_randomDamage - m_player->getTotalDefense());
        }
    }
}

void Combat::handleCombat(const char keyboardKey) {
    update(keyboardKey);
    m_combatState->handleCombat(this, keyboardKey);
}

bool Combat::isPlayerInRange() const {
    return m_player->isInRange(m_player->getPosition(), m_enemy->getPosition());
}

void Combat::displayCombatHeader() {
    GlobalSettings::setColor(COLOR_RED);
    std::cout << "\r------- IN Combat -------\n";
    GlobalSettings::setColor(COLOR_DEFAULT);
    std::flush(std::cout);
}

void Combat::handleCombatAttack() const {
    if (Position::isInRangeOfOne(m_player->getPosition().x, m_player->getPosition().y,
                                 m_enemy->getPosition().x, m_enemy->getPosition().y)) {
        // Both sides deal damage
        std::cout << "\n\rYou hit " << enemyTypeToString(m_enemy->getEnemyType()) << ". ";
        if (m_player->getTotalDefense() - m_randomDamage < 0) {
            std::cout << enemyTypeToString(m_enemy->getEnemyType()) << " hits you for ";
            GlobalSettings::setColor(COLOR_RED);
            std::cout << abs(m_player->getTotalDefense() - m_randomDamage);
            GlobalSettings::setColor(COLOR_DEFAULT);
            std::cout << " damage.    \n";
        } else {
            std::cout << "You defended yourself         \n";
        }
    } else if (isPlayerInRange()) {
        // Player attacks but is not counterattacked
        std::cout << "\n\rYou hit " << enemyTypeToString(m_enemy->getEnemyType()) << ".\n";
    }
    std::flush(std::cout);
}
