#include "tile.h"

#include <iostream>

Tile::Tile(std::string symbol) {
    if (symbol != "") {
        m_symbol = symbol;
    } else {
        m_symbol = "X";
        std::cout << "Tile: Error, cannot store an empty symbol" << std::endl;
    }
}

void Tile::draw() {
    std::cout << m_symbol;
}

Tile *Tile::createTile(TileType type) {
    switch (type) {
        default:
            return nullptr;
    }
}


