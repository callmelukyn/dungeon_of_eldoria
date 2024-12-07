#include "game.h"
#include "color.h"
#include "domain/entities/player.h"

Game::Game() {
    m_player = new Player(Role::warrior);
    m_menu = new Menu();
    m_levels = new Levels();
}

Game::~Game() {
    delete m_player;
    delete m_menu;
    delete m_levels;
}

void Game::render() {
    system("cls");
    switch (m_menu->getCurrentScreen()) {
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
    m_player->movePlayer(key, m_menu->getCurrentScreen(), m_levels->getMaps(), m_levels->getCurrentLevel(), [this] {
        m_levels->nextLevel(m_player);
    });
    // Handle movement on menu
    m_menu->handleMenuInput(key);
}


void Game::displayMap() const {
    m_levels->loadAllLevels();
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
