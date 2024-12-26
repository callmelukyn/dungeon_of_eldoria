#include "add_enemy.h"

#include "../domain/entities/mummy.h"
#include "../domain/entities/ghoul.h"
#include "../domain/entities/gargoil.h"
#include "../domain/entities/basilisk.h"
#include "../domain/entities/necromancer.h"

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

void AddEnemy::addGhoul(const int currentLevel, const Position position) {
    Enemy *ghoul = new Ghoul(position);
    m_enemies.push_back(ghoul);
    m_maps[currentLevel]->putCharacterInPosition(position, '!');
}

void AddEnemy::addGargoil(const int currentLevel, const Position position) {
    Enemy *gargoil = new Gargoil(position);
    m_enemies.push_back(gargoil);
    m_maps[currentLevel]->putCharacterInPosition(position, '!');
}

void AddEnemy::addBasilisk(int currentLevel, Position position) {
    Enemy *basilisk = new Basilisk(position);
    m_enemies.push_back(basilisk);
    m_maps[currentLevel]->putCharacterInPosition(position, '!');
}

void AddEnemy::addNecromancer(const int currentLevel, const Position position) {
    Enemy *necromancer = new Necromancer(position);
    m_enemies.push_back(necromancer);
    m_maps[currentLevel]->putCharacterInPosition(position, '!');
}

std::vector<Enemy *> AddEnemy::getEnemies() {
    return m_enemies;
}

void AddEnemy::clearEnemies() {
    m_enemies.clear();
}
