//
// Created by ivo on 11/16/2024.
//

#include "map.h"

Map::Map(const unsigned int mapHeight, const unsigned int mapWidth) : m_fullMap(mapHeight * mapWidth, '.') {
    m_mapHeight = mapHeight;
    m_mapWidth = mapWidth;

    for (unsigned int y = 0; y < m_mapHeight; ++y) {
        for (unsigned int x = 0; x < m_mapWidth; ++x) {
            if (y == 0 || y == m_mapHeight - 1 || x == 0 || x == m_mapWidth - 1) {
                m_fullMap[y * m_mapWidth + x] = '#'; // Border character
            }
        }
    }
}

void Map::printMap() {
    for (unsigned int y = 0; y < m_mapHeight; ++y) {
        for (unsigned int x = 0; x < m_mapWidth; ++x) {
            std::cout << (*this)(Position(x, y));
        }
        std::cout << '\n';
    }
}

