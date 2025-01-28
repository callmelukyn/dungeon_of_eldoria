#include "mage_builder.h"

MageBuilder::MageBuilder() = default;

MageBuilder::~MageBuilder() {
    delete m_player;
}

void MageBuilder::createPlayer() {
    m_player = new Player(Role::mage, 100, 2, 1, 2);
}
