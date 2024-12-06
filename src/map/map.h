//
// Created by ivo on 11/16/2024.
//

#ifndef MAP_H
#define MAP_H
#include <vector>

#include "../domain/entities/position.h"
#include "../domain/value_objects/doorPosition.h"


class Map {
    unsigned int m_mapHeight;
    unsigned int m_mapWidth;
    // Vector that holds all the characters for the map
    std::vector<char> m_fullMap;
    DoorPosition m_doorPosition;

    void putDoor(unsigned int x, unsigned int y);

public:
    Map(unsigned int mapHeight, unsigned int mapWidth, DoorPosition doorPosition);

    void putCharacterInPosition(Position position, char character);

    // Define operators to give both const and non-const access to the
    // positions in the map.
    char operator()(const Position position) const {
        return m_fullMap[position.y * m_mapWidth + position.x];
    }

    char &operator()(const Position position) {
        return m_fullMap[position.y * m_mapWidth + position.x];
    }

    void printMap();

    std::vector<char> getFullMap();

    void clearCharacterFromPosition(Position position);

    Position getStartingPosition(DoorPosition doorPosition) const;

    DoorPosition getDoorPosition() const;
};

#endif //MAP_H
