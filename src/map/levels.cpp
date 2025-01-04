#include "levels.h"

#include <iostream>
#include <map>


#include "../domain/entities/mummy.h"
#include "../tools/globalSettings.h"

Levels::Levels() {
    m_currentLevel = 0;
    m_maps.push_back(new Map(8, 10, DoorPosition::bottomDoor));
    m_maps.push_back(new Map(10, 15, DoorPosition::leftDoor));
    m_maps.push_back(new Map(10, 15, DoorPosition::bottomDoor));
    m_maps.push_back(new Map(15, 25, DoorPosition::rightDoor));
    m_maps.push_back(new Map(8, 10, DoorPosition::bottomDoor));
    m_maps.push_back(new Map(15, 25, DoorPosition::leftDoor));
    m_maps[0]->putCharacterInPosition(Position{5, 1}, '@');
    m_addEnemy = new AddEnemy(m_maps);
    m_addMerchant = new AddMerchant(m_maps);
    m_addPrisoner = new AddPrisoner(m_maps);
}

Levels::~Levels() {
    for (const Map *map: m_maps) {
        delete map;
    }
    delete m_addEnemy;
    delete m_addMerchant;
}

void Levels::loadAllLevels() const {
    static std::vector levelsLoaded(m_maps.size(), false);
    std::map<int, std::function<void()> > levels = {
        {0, [this] { level0(); }},
        {1, [this] { level1(); }},
        {2, [this] { level2(); }},
        {3, [this] { level3(); }},
        {4, [this] { level4(); }},
        {5, [this] { level5(); }}
    };
    if (!levelsLoaded[m_currentLevel]) {
        auto it = levels.find(m_currentLevel);
        if (it != levels.end()) {
            it->second();
            levelsLoaded[m_currentLevel] = true;
        }
    }
}

void Levels::renderCurrentLevel() const {
    if (m_currentLevel >= 0 && m_currentLevel < m_maps.size()) {
        m_maps[m_currentLevel]->printMap();
    }
}

void Levels::nextLevel(Player *player) {
    if (m_currentLevel + 1 < m_maps.size()) {
        clearCharactersFromPreviousLevel();
        GlobalSettings::clearConsoleOnNewScreen();
        const DoorPosition lastDoorPosition = m_maps[m_currentLevel]->getDoorPosition();
        // Advance to the next level
        ++m_currentLevel;
        //player->addXp(20);

        const Position newPlayerPosition = m_maps[m_currentLevel]->getStartingPosition(lastDoorPosition);
        // Put player on the side which he walked from
        player->setPlayerPosition(newPlayerPosition);
        m_maps[m_currentLevel]->putCharacterInPosition(newPlayerPosition, '@');
    } else {
        std::cout << "You have completed the game!" << std::endl;
    }
}

std::vector<Map *> Levels::getMaps() {
    return m_maps;
}

int Levels::getCurrentLevel() const {
    return m_currentLevel;
}

AddEnemy *Levels::getEnemy() const {
    return m_addEnemy;
}

AddMerchant *Levels::getMerchant() const {
    return m_addMerchant;
}

void Levels::clearCharactersFromPreviousLevel() const {
    for (Enemy *enemy: m_addEnemy->getEnemies()) {
        m_maps[m_currentLevel]->clearCharacterFromPosition(enemy->getEnemyPosition());
    }
    m_addEnemy->clearEnemies();
    m_maps[m_currentLevel]->clearCharacterFromPosition(m_addMerchant->getMerchant()->getPosition());
}

void Levels::level0() const {
    m_addEnemy->addMummy(m_currentLevel, Position{2, 4});
    m_addEnemy->addMummy(m_currentLevel, Position{1, 1});
    m_addMerchant->addMerchant(m_currentLevel, Position{4, 4});
    m_addPrisoner->addPrisoner(m_currentLevel, Position{3, 3});
}

void Levels::level1() const {
    m_addEnemy->addMummy(m_currentLevel, Position{2, 4});
    m_addEnemy->addMummy(m_currentLevel, Position{6, 4});
    m_addPrisoner->addPrisoner(m_currentLevel, Position{5, 6});
}

void Levels::level2() const {
    m_addEnemy->addMummy(m_currentLevel, Position{7, 6});
    m_addPrisoner->addPrisoner(m_currentLevel, Position{8, 3});
}

void Levels::level3() const {
    m_addEnemy->addMummy(m_currentLevel, Position{10, 4});
    m_addEnemy->addMummy(m_currentLevel, Position{13, 8});
    m_addPrisoner->addPrisoner(m_currentLevel, Position{4, 6});
}

void Levels::level4() const {
    m_addMerchant->addMerchant(m_currentLevel, Position{6, 3});
}

void Levels::level5() const {
    m_addEnemy->addMummy(m_currentLevel, Position{4, 12});
    m_addEnemy->addBasilisk(m_currentLevel, Position{6, 8}); //Ten pujde do vetsiho levelu
    m_addPrisoner->addPrisoner(m_currentLevel, Position{12, 9});
}
