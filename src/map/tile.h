#ifndef TILE_H
#define TILE_H


class Tile {
    char m_symbol;

    explicit Tile(char symbol);

public:
    static Tile *createTile(char symbol);

    char getTile() const;
};


#endif //TILE_H
