//
// Created by ivo on 11/16/2024.
//

#ifndef MAP_H
#define MAP_H
#include <vector>

#include <fstream>
#include <iostream>

#include "../domain/entities/position.h"


class Map {
    unsigned m_worldHeight;
    unsigned m_worldWidth;

    // Declare a variable that will hold all the characters for the map
    std::vector<char> m_worldMap;

public:
    explicit Map(Position position);

    // Define operators to give both const and non-const access to the
    // positions in the map.
    char operator()(const unsigned y, const unsigned x) const { return m_worldMap[y * m_worldWidth + x]; }
    char &operator()(const unsigned y, const unsigned x) { return m_worldMap[y * m_worldWidth + x]; }

    void print();
};

#endif //MAP_H
