#ifndef TILE_H
#define TILE_H
#include <string>

enum class TileType {
};

class Tile {
    std::string m_symbol;

    Tile(std::string symbol);

public:
    static Tile *createTile(TileType type);

    void draw();
};


#endif //TILE_H
