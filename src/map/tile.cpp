#include "tile.h"

Tile::Tile(const char symbol) {
    m_symbol = symbol;
}

Tile *Tile::createTile(const char symbol) {
    return new Tile(symbol);
}

char Tile::getTile() const {
    return m_symbol;
}
