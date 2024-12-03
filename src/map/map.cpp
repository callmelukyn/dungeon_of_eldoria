//
// Created by ivo on 11/16/2024.
//

#include "map.h"

#include <iostream>

Map::Map(const unsigned int mapHeight, const unsigned int mapWidth) : m_fullMap(mapHeight * mapWidth, '.') {
    m_mapHeight = mapHeight;
    m_mapWidth = mapWidth;
}

void Map::putCharacterInPosition(const Position position, const char character) {
    m_fullMap[position.y * m_mapWidth + position.x] = character;
}

void Map::printMap(const DoorPosition doorPosition) {
    for (unsigned int y = 0; y < m_mapHeight; ++y) {
        for (unsigned int x = 0; x < m_mapWidth; ++x) {
            if (y == 0 || y == m_mapHeight - 1 || x == 0 || x == m_mapWidth - 1) {
                m_fullMap[y * m_mapWidth + x] = '#'; // Border character
                putDoor(doorPosition, x, y);
            }
            std::cout << (*this)(Position(x, y));
        }
        std::cout << '\n';
    }
}

std::vector<char> Map::getFullMap() {
    return m_fullMap;
}

auto Map::putDoor(const DoorPosition doorPosition, const unsigned int x, const unsigned int y) -> void {
    const unsigned int middleRow = m_mapHeight / 2; // Middle of the vertical borders
    const unsigned int middleCol = m_mapWidth / 2; // Middle of the horizontal borders

    switch (doorPosition) {
        case DoorPosition::leftDoor:
            if (y == middleRow) {
                m_fullMap[y * m_mapWidth] = 'D';
            }
            break;
        case DoorPosition::rightDoor:
            if (y == middleRow) {
                m_fullMap[y * m_mapWidth + (m_mapWidth - 1)] = 'D';
            }
            break;
        case DoorPosition::topDoor:
            if (x == middleCol) {
                m_fullMap[x] = 'D';
            }
            break;
        case DoorPosition::bottomDoor:
            if (x == middleCol) {
                m_fullMap[(m_mapHeight - 1) * m_mapWidth + x] = 'D';
            }
            break;
    }
}


