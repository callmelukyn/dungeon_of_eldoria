//
// Created by ivo on 11/16/2024.
//

#include "map.h"
#include <cassert>
#include <iostream>

Map::Map(const unsigned int mapHeight, const unsigned int mapWidth, const DoorPosition doorPosition)
    : m_fullMap(mapHeight * mapWidth, '.') {
    m_mapHeight = mapHeight;
    m_mapWidth = mapWidth;
    m_doorPosition = doorPosition;
}

void Map::putCharacterInPosition(const Position position, const char character) {
    // Ensure the position is within the bounds of the map
    assert(("Character is not within the bounds of the map",
        position.y > 0 && position.y < m_mapHeight && position.x > 0 && position.x < m_mapWidth));
    m_fullMap[position.y * m_mapWidth + position.x] = character;
}

// Get position of a single tile
char Map::assignTilePosition(const Position position) const {
    return m_fullMap[position.y * m_mapWidth + position.x];
}

void Map::printMap() {
    for (unsigned int y = 0; y < m_mapHeight; y++) {
        for (unsigned int x = 0; x < m_mapWidth; x++) {
            if (y == 0 || y == m_mapHeight - 1 || x == 0 || x == m_mapWidth - 1) {
                m_fullMap[y * m_mapWidth + x] = '#'; // Border character
                putDoor(x, y);
            }
            std::cout << assignTilePosition(Position(x, y));
        }
        std::cout << '\n';
    }
}

std::vector<char> Map::getFullMap() {
    return m_fullMap;
}

void Map::putDoor(const unsigned int x, const unsigned int y) {
    // Middle of the vertical borders
    const unsigned int middleRow = m_mapHeight / 2;
    // Middle of the horizontal borders
    const unsigned int middleCol = m_mapWidth / 2;

    switch (m_doorPosition) {
        case DoorPosition::leftDoor:
            if (y == middleRow) {
                m_fullMap[y * m_mapWidth] = '|';
            }
            break;
        case DoorPosition::rightDoor:
            if (y == middleRow) {
                m_fullMap[y * m_mapWidth + (m_mapWidth - 1)] = '|';
            }
            break;
        case DoorPosition::topDoor:
            if (x == middleCol) {
                m_fullMap[x] = '|';
            }
            break;
        case DoorPosition::bottomDoor:
            if (x == middleCol) {
                m_fullMap[(m_mapHeight - 1) * m_mapWidth + x] = '|';
            }
            break;
    }
}

Position Map::getStartingPosition(const DoorPosition doorPosition) const {
    switch (doorPosition) {
        case DoorPosition::bottomDoor:
            assert(("Door should not be placed on the same side which player walked from",
                m_doorPosition != DoorPosition::topDoor));
        // Enter on the top of the new map
            return Position{m_mapWidth / 2, 1};
        case DoorPosition::topDoor:
            assert(("Door should not be placed on the same side which player walked from",
                m_doorPosition != DoorPosition::bottomDoor));
        // Enter on the bottom
            return Position{m_mapWidth / 2, m_mapHeight - 2};
        case DoorPosition::rightDoor:
            assert(("Door should not be placed on the same side which player walked from",
                m_doorPosition != DoorPosition::leftDoor));
        // Enter on the left side
            return Position{1, m_mapHeight / 2};
        case DoorPosition::leftDoor:
            assert(("Door should not be placed on the same side which player walked from",
                m_doorPosition != DoorPosition::rightDoor));
        // Enter on the right side
            return Position{m_mapWidth - 2, m_mapHeight / 2};
        default:
            return Position{1, 1};
    }
}

DoorPosition Map::getDoorPosition() const {
    return m_doorPosition;
}

void Map::clearCharacterFromPosition(const Position position) {
    // Ensure the position is within the bounds of the map
    if (position.y > 0 && position.y < m_mapHeight &&
        position.x > 0 && position.x < m_mapWidth) {
        // Replace with empty character
        m_fullMap[position.y * m_mapWidth + position.x] = '.';
    }
}
