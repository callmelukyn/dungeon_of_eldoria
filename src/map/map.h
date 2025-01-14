//
// Created by ivo on 11/16/2024.
//

#ifndef MAP_H
#define MAP_H
#include <vector>

#include "position.h"
#include "tile.h"
#include "../domain/value_objects/door_position.h"

class Map {
    unsigned int m_mapHeight;
    unsigned int m_mapWidth;
    // Vector that holds all the characters for the map
    std::vector<Tile *> m_fullMap;
    DoorPosition m_doorPosition;

    void putDoor(unsigned int x, unsigned int y);

public:
    Map(unsigned int mapHeight, unsigned int mapWidth, DoorPosition doorPosition);

    void putCharacterInPosition(Position position, char character);

    char assignTilePosition(Position position) const;

    void printMap();

    std::vector<Tile *> getFullMap();

    void clearCharacterFromPosition(Position position);

    Position getStartingPosition(DoorPosition doorPosition) const;

    DoorPosition getDoorPosition() const;
};

#endif //MAP_H
