#include "mage_builder.h"

MageBuilder::MageBuilder() = default;

MageBuilder::~MageBuilder() {
    delete m_player;
}

void MageBuilder::createPlayer() {
    m_player = new Player(Role::mage, 20, 10, 5, 5);
}
