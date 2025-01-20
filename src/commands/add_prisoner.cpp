//
// Created by Lukyn on 23.12.2024.
//

#include "add_prisoner.h"

AddPrisoner::AddPrisoner(const std::vector<Map *> &maps) {
    m_prisoners = {};
    m_maps = maps;
    m_positionOfPrisoners = Position{0, 0};
}

AddPrisoner::~AddPrisoner() {
    for (const Prisoner *prisoner: m_prisoners) {
        delete prisoner;
    }
    m_prisoners.clear();
}

void AddPrisoner::addPrisoner(const int currentLevel, const Position position) {
    Prisoner *prisoner = new Prisoner(position);
    m_prisoners.push_back(prisoner);
    m_maps[currentLevel]->putCharacterInPosition(position, '?');
}

std::vector<Prisoner *> AddPrisoner::getPrisoners() {
    return m_prisoners;
}

void AddPrisoner::clearPrisoners() {
    m_prisoners.clear();
}
