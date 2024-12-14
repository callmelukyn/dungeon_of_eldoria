#include "levels.h"

#include <iostream>

#include "../tools/globalSettings.h"

Levels::Levels() {
    m_currentLevel = 0;
    m_maps.push_back(new Map(8, 10, DoorPosition::bottomDoor));
    m_maps.push_back(new Map(10, 15, DoorPosition::leftDoor));
    m_maps.push_back(new Map(10, 15, DoorPosition::bottomDoor));
    m_maps.push_back(new Map(15, 25, DoorPosition::rightDoor));
    m_maps.push_back(new Map(8, 10, DoorPosition::bottomDoor));
    m_maps.push_back(new Map(15, 25, DoorPosition::leftDoor));
    m_maps[0]->putCharacterInPosition(Position{5, 1}, '@');
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
    level2(map);
    level3(map);
    level4(map);
    level5(map);
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
        map->putCharacterInPosition(Position{3, 3}, '?'); //Prisoner
        map->printMap();
    }
}

void Levels::level1(Map *map) const {
    if (m_currentLevel == 1) {
        map->putCharacterInPosition(Position{6, 4}, '!'); //Mummy
        map->putCharacterInPosition(Position{5, 6}, '?'); //Prisoner
        map->printMap();
    }
}

void Levels::level2(Map *map) const {
    if (m_currentLevel == 2) {
        map->putCharacterInPosition(Position{7, 6}, '!'); //Mummy
        map->putCharacterInPosition(Position{8, 3}, '?'); //Prisoner
        map->printMap();
    }
}

void Levels::level3(Map *map) const {
    if (m_currentLevel == 3) {
        map->putCharacterInPosition(Position{10, 4}, '!'); //Mummy
        map->putCharacterInPosition(Position{13, 8}, '!'); //Mummy
        map->putCharacterInPosition(Position{4, 6}, '?'); //Prisoner
        map->printMap();
    }
}

void Levels::level4(Map *map) const {
    if (m_currentLevel == 4) {
        map->putCharacterInPosition(Position{6, 3}, '$'); //Merchant level
        map->printMap();
    }
}

void Levels::level5(Map *map) const {
    if (m_currentLevel == 5) {
        map->putCharacterInPosition(Position{4, 12}, '!'); //Mummy
        map->putCharacterInPosition(Position{6, 8}, '!'); //Basilisk
        map->putCharacterInPosition(Position{12, 9}, '?'); //Prisoner
        map->printMap();
    }
}
