//
// Created by ivo on 11/16/2024.
//

#include "map.h"

#include <iostream>

Map::Map(unsigned int width, unsigned int height) {
    std::vector<Tile *> row(width, nullptr);
    for (int i = 0; i < height; ++i) {
        m_map.push_back(row);
    }
}

void Map::draw() {
    for (std::vector<Tile *> row: m_map) {
        for (Tile *tile: row) {
            if (tile != nullptr) {
                tile->draw();
            } else {
                std::cout << ".";
            }
        }
        std::cout << "\n";
    }
}

void Map::setTile(unsigned int row, unsigned int column, Tile *tile) {
    int height = m_map.size();
    int width = m_map.at(0).size();

    if ((row >= height) or (column >= width)) {
        std::cout << "row or column out of range",
                "Map::setTile";

        return;
    }

    if (m_map.at(row).at(column) != nullptr) {
        std::cout << "Place [" + std::to_string(row) + ","
                + std::to_string(column) + "] already occupied",
                "Map::setTile";
        return;
    }

    m_map.at(row).at(column) = tile;

    /*
    if ((row < height) and (column < width)){
        if (m_map.at(row).at(column) == nullptr){
            m_map.at(row).at(column) = tile;
        }
    }
     */
}


Map::~Map() {
    for (std::vector<Tile *> row: m_map) {
        for (Tile *tile: row) {
            if (tile != nullptr) {
                delete tile;
            }
        }
    }
}

