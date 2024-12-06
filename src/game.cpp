#include "game.h"
#include "color.h"
#include "domain/entities/player.h"

Game::Game(): m_player(new Player(Role::warrior)) {
    m_menu = new Menu();
    m_menu->m_currentScreen = Screen::mainMenu;
    m_maps.push_back(new Map(15, 35, DoorPosition::bottomDoor));
    m_maps.push_back(new Map(15, 20, DoorPosition::leftDoor));
    m_currentLevel = 0;
}

Game::~Game() {
    delete m_player;
    delete m_menu;
    for (const Map *map: m_maps) {
        delete map;
    }
}

void Game::render() {
    system("cls");
    switch (m_menu->m_currentScreen) {
        case Screen::mainMenu:
            m_menu->displayMainMenu();
            break;
        case Screen::roleMenu:
            m_menu->displayRoleMenu();
            break;
        case Screen::creditsMenu:
            m_menu->displayCreditsMenu();
            break;
        case Screen::howToPlayMenu:
            m_menu->displayHowToPlay();
            break;
        case Screen::game:
            displayGUI();
            break;
    }
}

void Game::handleInputs(const char key) {
    // Handle movement on the map
    m_player->movePlayer(key, m_menu->m_currentScreen, m_maps, m_currentLevel, [this] {
        this->nextLevel();
    });
    // Handle movement on menu
    m_menu->handleMenuInput(key);
}


void Game::displayMap() const {
    Map *map = m_maps[m_currentLevel];
    map->putCharacterInPosition(Position(m_player->getPlayerPosition()), '@');
    map->printMap();
}

void Game::displayGUI() {
    m_menu->smallHeaderMenu();
    displayPlayerProperties();
    displayMap();
    displayHelp();
}

void Game::displayHelp() const {
    std::cout << "[WASD] Move around" << "\n";
    std::cout << "[F] Fight" << "\n";
    std::cout << "[E] Interact" << "\n";
    std::cout << "[H] Use Heal Potion" << "\n";
}

void Game::displayPlayerProperties() const {
    std::cout << "HP: ";
    setColor(04);
    std::cout << m_player->getHp();
    setColor(07);
    std::cout << "        COINS: ";
    setColor(06);
    std::cout << m_player->getCoins() << "\n";
    setColor(07);
    std::cout << "XP: " << m_player->getXp() << "/100";
    std::cout << "     HEAL POTIONS: ";
    std::cout << m_player->getNumberOfPotions() << "\n";
}

void Game::loadLevel(const int level) {
    if (level >= 0 && level < m_maps.size()) {
        m_currentLevel = level;
        m_maps[m_currentLevel]->putCharacterInPosition(m_player->getPlayerPosition(), '@');
    }
}

void Game::nextLevel() {
    if (m_currentLevel + 1 < m_maps.size()) {
        const DoorPosition lastDoorPosition = m_maps[m_currentLevel]->getDoorPosition();
        // Advance to the next level
        ++m_currentLevel;
        // Put player on the side which he walked from
        m_player->setPlayerPosition(m_maps[m_currentLevel]->getStartingPosition(lastDoorPosition));
        loadLevel(m_currentLevel);
    } else {
        std::cout << "You have completed the game!" << std::endl;
        m_menu->m_currentScreen = Screen::mainMenu;
    }
}

