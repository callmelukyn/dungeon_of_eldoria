#include "archerBuilder.h"

ArcherBuilder::ArcherBuilder() = default;

ArcherBuilder::~ArcherBuilder() {
    delete m_player;
}

void ArcherBuilder::createPlayer() {
    m_player = new Player(Role::archer, 50, 12, 8, 3, 1);
}
