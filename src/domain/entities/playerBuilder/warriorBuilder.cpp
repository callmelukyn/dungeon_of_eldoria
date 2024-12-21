#include "warriorBuilder.h"

WarriorBuilder::WarriorBuilder() = default;

WarriorBuilder::~WarriorBuilder() {
    delete m_player;
}

void WarriorBuilder::createPlayer() {
    m_player = new Player(Role::warrior, 100, 15, 15, 1, 1);
}

