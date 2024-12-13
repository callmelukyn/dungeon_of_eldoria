#include "playerDirector.h"


PlayerDirector::PlayerDirector(PlayerBuilder *builder) {
    m_builder = builder;
}

void PlayerDirector::setBuilder(PlayerBuilder *builder) {
    m_builder = builder;
}

Player *PlayerDirector::createPlayer() const {
    m_builder->createPlayer();
    return m_builder->getPlayer();
}
