#include "add_enemy.h"

#include "../domain/entities/mummy.h"

AddEnemy::AddEnemy(const std::vector<Map *> &maps) {
    m_enemies = {};
    m_maps = maps;
}

AddEnemy::~AddEnemy() {
    for (const Enemy *enemy: m_enemies) {
        delete enemy;
    }
    // for (const Map *map: m_maps) {
    //     delete map;
    // }
    m_enemies.clear();
}

void AddEnemy::addMummy(const int currentLevel, const Position position) {
    Enemy *mummy = new Mummy(position);
    m_enemies.push_back(mummy);
    m_maps[currentLevel]->putCharacterInPosition(position, '!');
}

std::vector<Enemy *> AddEnemy::getEnemies() {
    return m_enemies;
}

void AddEnemy::clearEnemies() {
    m_enemies.clear();
}
