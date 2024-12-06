#include "game.h"
#include "color.h"
#include "domain/entities/player.h"

Game::Game(): m_player(new Player(Role::warrior)), m_position(7, 1) {
    m_menu = new Menu();
    m_menu->m_currentScreen = Screen::mainMenu;
}

Game::~Game() {
    delete m_player;
    delete m_menu;
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

void Game::handleGameInput(const char key) {
    m_menu->handleMenuInput(key);
    if (Screen::game == m_menu->m_currentScreen) {
        switch (key) {
            case 'w':
                m_position.y -= 1;
                break;
            case 's':
                m_position.y += 1;
                break;
            case 'a':
                m_position.x -= 1;
                break;
            case 'd':
                m_position.x += 1;
                break;
            default: break;
        }
    }
    m_player->movePlayer(key, m_menu->m_currentScreen);
}

void Game::displayMap() {
    displayFirstLevel();
}

void Game::displayFirstLevel() {
    Map *map = new Map(15, 35);
    // Position position = Position({5, 8});
    m_player->setPlayerPosition(Position{1, 10});
    map->putCharacterInPosition(m_position, '@');
    map->printMap(DoorPosition::bottomDoor);
    delete map;
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

Screen Game::getCurrentScreen() const {
    return m_menu->m_currentScreen;
}



