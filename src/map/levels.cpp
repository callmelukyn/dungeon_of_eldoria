#include "levels.h"

#include <functional>
#include <iostream>
#include <unordered_map>

#include "../tools/global_settings.h"

Levels::Levels() {
    m_currentLevel = 0;
    m_maps.reserve(10); // Reserve memory for the number of caves.
    m_maps.push_back(new Map(8, 10, DoorPosition::bottomDoor)); //level 0
    m_maps.push_back(new Map(10, 15, DoorPosition::leftDoor)); //level 1
    m_maps.push_back(new Map(10, 15, DoorPosition::bottomDoor)); //level 2
    m_maps.push_back(new Map(15, 25, DoorPosition::rightDoor)); //level 3
    m_maps.push_back(new Map(8, 10, DoorPosition::bottomDoor)); //level 4
    m_maps.push_back(new Map(15, 18, DoorPosition::leftDoor)); //level 5
    m_maps.push_back(new Map(11, 30, DoorPosition::bottomDoor)); //level 6
    m_maps.push_back(new Map(12, 33, DoorPosition::bottomDoor)); //level 7
    m_maps.push_back(new Map(14, 28, DoorPosition::rightDoor)); //level 8
    m_maps.push_back(new Map(8, 10, DoorPosition::bottomDoor)); //level 9
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
    delete m_addPrisoner;
}

void Levels::loadAllLevels() const {
    static std::vector levelsLoaded(m_maps.size(), false);
    std::unordered_map<int, std::function<void()> > levels = {
        {0, [this] { level0(); }},
        {1, [this] { level1(); }},
        {2, [this] { level2(); }},
        {3, [this] { level3(); }},
        {4, [this] { level4(); }},
        {5, [this] { level5(); }},
        {6, [this] { level6(); }},
        {7, [this] { level7(); }},
        {8, [this] { level8(); }},
        {9, [this] { level9(); }}
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
        player->addXp(10);

        const Position newPlayerPosition = m_maps[m_currentLevel]->getStartingPosition(lastDoorPosition);
        // Put player on the side which he walked from
        player->setPosition(newPlayerPosition);
        m_maps[m_currentLevel]->putCharacterInPosition(newPlayerPosition, '@');
    } else {
        //TODO
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

AddPrisoner *Levels::getPrisoner() const {
    return m_addPrisoner;
}

void Levels::clearCharactersFromPreviousLevel() const {
    for (const Enemy *enemy: m_addEnemy->getEnemies()) {
        m_maps[m_currentLevel]->clearCharacterFromPosition(enemy->getPosition());
    }
    m_addEnemy->clearEnemies();
    if (m_addMerchant->getMerchant() != nullptr) {
        m_maps[m_currentLevel]->clearCharacterFromPosition(m_addMerchant->getMerchant()->getPosition());
        m_addMerchant->setMerchantToNull();
    }
    for (const Prisoner *prisoner: m_addPrisoner->getPrisoners()) {
        m_maps[m_currentLevel]->clearCharacterFromPosition(prisoner->getPosition());
    }
    m_addPrisoner->clearPrisoners();
}

void Levels::level0() const {
    m_addEnemy->addMummy(m_currentLevel, Position{2, 4});
    m_addPrisoner->addPrisoner(m_currentLevel, Position{3, 3});
}

void Levels::level1() const {
    m_addEnemy->addMummy(m_currentLevel, Position{2, 4});
    m_addEnemy->addMummy(m_currentLevel, Position{6, 4});
    m_addPrisoner->addPrisoner(m_currentLevel, Position{5, 6});
}

void Levels::level2() const {
    m_addEnemy->addMummy(m_currentLevel, Position{4, 4});
    m_addEnemy->addMummy(m_currentLevel, Position{7, 6});
    m_addPrisoner->addPrisoner(m_currentLevel, Position{8, 3});
    m_addPrisoner->addPrisoner(m_currentLevel, Position{5, 4});
}

void Levels::level3() const {
    m_addEnemy->addMummy(m_currentLevel, Position{10, 4});
    m_addEnemy->addMummy(m_currentLevel, Position{13, 8});
    m_addEnemy->addGhoul(m_currentLevel, Position{5, 8});
    m_addPrisoner->addPrisoner(m_currentLevel, Position{4, 6});
    m_addPrisoner->addPrisoner(m_currentLevel, Position{12, 7});
}

void Levels::level4() const {
    m_addMerchant->addMerchant(m_currentLevel, Position{6, 3});
}

void Levels::level5() const {
    m_addEnemy->addGhoul(m_currentLevel, Position{4, 12});
    m_addEnemy->addGhoul(m_currentLevel, Position{6, 8});
    m_addPrisoner->addPrisoner(m_currentLevel, Position{12, 9});
}

void Levels::level6() const {
    m_addEnemy->addGhoul(m_currentLevel, Position{15, 8});
    m_addEnemy->addGhoul(m_currentLevel, Position{10, 6});
    m_addPrisoner->addPrisoner(m_currentLevel, Position{12, 9});
}

void Levels::level7() const {
    m_addEnemy->addGargoyle(m_currentLevel, Position{15, 8});
    m_addEnemy->addGargoyle(m_currentLevel, Position{10, 3});
    m_addPrisoner->addPrisoner(m_currentLevel, Position{25, 2});
}

void Levels::level8() const {
    m_addEnemy->addGargoyle(m_currentLevel, Position{8, 4});
    m_addEnemy->addGhoul(m_currentLevel, Position{4, 11});
    m_addEnemy->addMummy(m_currentLevel, Position{17, 2});
    m_addPrisoner->addPrisoner(m_currentLevel, Position{19, 6});
    m_addPrisoner->addPrisoner(m_currentLevel, Position{25, 3});
}

void Levels::level9() const {
    m_addMerchant->addMerchant(m_currentLevel, Position{6, 3});
}

bool Levels::isAnyPrisonerInRange(const Player *player) const {
    bool isPrisonerInRange = false;
    for (const Prisoner *prisoner: m_addPrisoner->getPrisoners()) {
        if (Position::isInRangeOfOne(player->getPosition().x, player->getPosition().y,
                                     prisoner->getPosition().x, prisoner->getPosition().y)) {
            isPrisonerInRange = true;
            return isPrisonerInRange;
        }
    }
    return isPrisonerInRange;
}

bool Levels::isAnyEnemyInRange(const Player *player) const {
    bool isEnemyInRange = false;
    for (const Enemy *enemy: m_addEnemy->getEnemies()) {
        if (player->isInRange(player->getPosition(), enemy->getPosition())) {
            isEnemyInRange = true;
            return isEnemyInRange;
        }
    }
    return isEnemyInRange;
}
