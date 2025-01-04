#include "game.h"

#include <iostream>

#include "tools/globalSettings.h"
#include "domain/entities/player.h"

Game::Game() {
    m_menu = new Menu();
    m_levels = new Levels();
    m_player = nullptr;
}

Game::~Game() {
    delete m_menu;
    delete m_levels;
    delete m_player;
}

void Game::render() {
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
        case Screen::cutscenes:
            m_menu->displayCutscenes();
            break;
        case Screen::shopMain:
            m_menu->getShop()->displayShopMain(m_menu->getSelected());
            break;
        case Screen::shopWeapons:
            m_menu->getShop()->displayShopWeapons(m_menu->getSelected(), m_player);
            break;
        case Screen::shopArmor:
            m_menu->getShop()->displayShopArmor(m_menu->getSelected(), m_player);
            break;
        case Screen::shopPotions:
            m_menu->getShop()->displayShopPotions(m_menu->getSelected(), m_player);
            break;
        case Screen::game:
            initializePlayer();
            m_player->checkLevelStatus();
            displayGUI();
            break;
    }
}

void Game::handleInputs(const char keyboardKey) const {
    if (m_player) {
        // Handle player movement on the map.
        m_player->movePlayer(keyboardKey, m_menu->getCurrentScreen(), m_levels->getMaps(),
                             m_levels->getCurrentLevel(), [this] { m_levels->nextLevel(m_player); },
                             m_levels->getEnemy()->getEnemies());
        // Handle movement for enemies.
        for (Enemy *enemy: m_levels->getEnemy()->getEnemies()) {
            if (!m_levels->getEnemy()->getEnemies().empty()) {
                enemy->moveEnemy(m_menu->getCurrentScreen(), m_levels->getMaps(), m_levels->getCurrentLevel(),
                                 m_player, keyboardKey);
            }
        }
        m_levels->getMerchant()->getMerchant()->interaction(m_menu->getCurrentScreen(), m_player,
                                                            keyboardKey, [this] {
                                                                m_menu->changeScreenNormal(Screen::shopMain);
                                                            });
    }
    // Handle movement on menu.
    m_menu->handleMenuInput(keyboardKey, m_player);
}

void Game::displayGUI() const {
    m_menu->smallHeaderMenu();
    displayPlayerProperties();
    m_levels->loadAllLevels();
    m_levels->renderCurrentLevel();
    displayHelp();
}

void Game::displayHelp() const {
    std::cout << "\n[WASD] Move around" << "\n";
    std::cout << "[F] Fight" << "\n";
    std::cout << "[E] Interact" << "\n";
    std::cout << "[H] Use Heal Potion" << "\n";
}

void Game::displayPlayerProperties() const {
    std::cout << "HP: ";
    GlobalSettings::setColor(COLOR_RED);
    std::cout << m_player->getHp();
    GlobalSettings::setColor(COLOR_DEFAULT);
    std::cout << "        COINS: ";
    GlobalSettings::setColor(COLOR_YELLOW);
    std::cout << m_player->getCoins() << "\n";
    GlobalSettings::setColor(COLOR_DEFAULT);
    std::cout << "LVL: " << m_player->getLevel() << "      -     " << m_player->getXp() << "/100 XP\n";
    std::cout << "HEAL POTIONS: ";
    std::cout << m_player->getNumberOfPotions() << "\n";
    std::cout << "CAVE: " << m_levels->getCurrentLevel() + 1 << "\n\n";
}

Player *Game::initializePlayer() {
    if (m_player == nullptr) {
        m_player = m_menu->getPlayerDirector()->createPlayer();
    }
    return m_player;
}
