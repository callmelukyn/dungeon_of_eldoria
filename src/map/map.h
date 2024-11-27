//
// Created by ivo on 11/16/2024.
//

#ifndef MAP_H
#define MAP_H
#include <vector>

#include "tile.h"


class Map {
    std::vector<std::vector<Tile *> > m_map;

public:
    Map(unsigned int width, unsigned int height);

    ~Map();

    void draw();

    void setTile(unsigned int row, unsigned int column, Tile *tile);

    unsigned int getGoldPerTurnFromTile(unsigned int row, unsigned int column);
};


#endif //MAP_H
