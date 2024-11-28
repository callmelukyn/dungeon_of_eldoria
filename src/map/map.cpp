//
// Created by ivo on 11/16/2024.
//

#include "map.h"

Map::Map(const Position position) : m_worldMap(position.x * position.y, '.') {
    m_worldHeight = position.x;
    m_worldWidth = position.y;

    for (unsigned y = 0; y < m_worldHeight; ++y) {
        for (unsigned x = 0; x < m_worldWidth; ++x) {
            if (y == 0 || y == m_worldHeight - 1 || x == 0 || x == m_worldWidth - 1) {
                m_worldMap[y * m_worldWidth + x] = '#'; // Border character
            }
        }
    }
}

void Map::print() {
    for (unsigned y = 0; y < m_worldHeight; ++y) {
        for (unsigned x = 0; x < m_worldWidth; ++x) {
            std::cout << (*this)(y, x);
        }
        std::cout << '\n';
    }
}

