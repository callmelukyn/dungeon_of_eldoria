#include "archer_builder.h"

ArcherBuilder::ArcherBuilder() = default;

ArcherBuilder::~ArcherBuilder() {
    delete m_player;
}

void ArcherBuilder::createPlayer() {
    m_player = new Player(Role::archer, 100, 5, 8, 2);
}
