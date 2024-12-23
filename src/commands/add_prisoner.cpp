//
// Created by Lukyn on 23.12.2024.
//

#include "add_prisoner.h"

AddPrisoner::AddPrisoner(const std::vector<Map *> &maps) {
    m_prisoner = nullptr;
    m_maps = maps;
}

AddPrisoner::~AddPrisoner() {
    delete m_prisoner;
}

void AddPrisoner::addPrisoner(int currentLevel, Position position) {
    m_prisoner = new Prisoner(position);
    m_maps[currentLevel]->putCharacterInPosition(position, '?');
}

Prisoner *AddPrisoner::getPrisoner() const {
    return m_prisoner;
}
