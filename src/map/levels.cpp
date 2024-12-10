#include "levels.h"

#include <iostream>

#include "../Tools/GlobalSettings.h"

Levels::Levels() {
    m_currentLevel = 0;
    m_maps.push_back(new Map(15, 35, DoorPosition::bottomDoor));
    m_maps.push_back(new Map(15, 20, DoorPosition::leftDoor));
    m_maps[0]->putCharacterInPosition(Position{2, 2}, '@');
}

Levels::~Levels() {
    for (const Map *map: m_maps) {
        delete map;
    }
}

void Levels::loadAllLevels() const {
    Map *map = m_maps[m_currentLevel];
    level0(map);
    level1(map);
}

void Levels::nextLevel(Player *player) {
    if (m_currentLevel + 1 < m_maps.size()) {
        GlobalSettings::clearConsoleOnNewScreen();
        const DoorPosition lastDoorPosition = m_maps[m_currentLevel]->getDoorPosition();
        // Advance to the next level
        ++m_currentLevel;

        const Position newPlayerPosition = m_maps[m_currentLevel]->getStartingPosition(lastDoorPosition);
        // Put player on the side which he walked from
        player->setPlayerPosition(newPlayerPosition);
        m_maps[m_currentLevel]->putCharacterInPosition(newPlayerPosition, '@');
        loadLevel(m_currentLevel);
    } else {
        std::cout << "You have completed the game!" << std::endl;
    }
}

void Levels::loadLevel(const int level) {
    if (level >= 0 && level < m_maps.size()) {
        m_currentLevel = level;
    }
}

std::vector<Map *> Levels::getMaps() {
    return m_maps;
}

int Levels::getCurrentLevel() const {
    return m_currentLevel;
}

void Levels::level0(Map *map) const {
    if (m_currentLevel == 0) {
        map->putCharacterInPosition(Position{4, 6}, '!');
        map->printMap();
    }
}

void Levels::level1(Map *map) const {
    if (m_currentLevel == 1) {
        map->putCharacterInPosition(Position{4, 6}, '!');
        map->printMap();
    }
}

