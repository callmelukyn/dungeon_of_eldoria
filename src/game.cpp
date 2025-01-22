#include "game.h"

#include <iostream>

#include "combat_system/combat.h"
#include "domain/entities/player.h"
#include "interactions/healing_interaction.h"
#include "interactions/merchant_interaction.h"
#include "interactions/prisoner_interaction.h"
#include "movement/enemy_movement.h"
#include "movement/player_movement.h"
#include "tools/global_settings.h"

Game::Game() {
    m_playerDirector = new PlayerDirector(nullptr);
    m_menu = new Menu(m_playerDirector);
    m_levels = new Levels();
    m_player = nullptr;
}

Game::~Game() {
    delete m_playerDirector;
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
    // Handle movement on menu.
    m_menu->handleMenuInput(keyboardKey, m_player);
    if (!(m_player && m_menu->getCurrentScreen() == Screen::game)) {
        return;
    }
    // Handle player movement on the map.
    const PlayerMovement *playerMovement = new PlayerMovement(m_player);
    playerMovement->movePlayer(keyboardKey, m_levels->getMaps(),
                               m_levels->getCurrentLevel(), [this] { m_levels->nextLevel(m_player); },
                               m_levels->getEnemy()->getEnemies());
    // Handle movement for enemies.
    for (Enemy *enemy: m_levels->getEnemy()->getEnemies()) {
        EnemyMovement *enemyMovement = new EnemyMovement(enemy);
        Combat *combat = new Combat(enemy, m_player);
        combat->handleCombat(keyboardKey);
        if (!m_levels->getEnemy()->getEnemies().empty() && enemy->isAlive()) {
            enemyMovement->moveEnemy(m_levels->getMaps(), m_levels->getCurrentLevel(),
                                     m_player, keyboardKey);
            // enemy->moveEnemy(m_levels->getMaps(), m_levels->getCurrentLevel(),
            //                  m_player, keyboardKey);
            enemy->checkEnemyHp(m_levels->getMaps(), m_player, m_levels->getCurrentLevel());
        }
        delete combat;
        delete enemyMovement;
    }
    // Handle interaction with merchant
    MerchantInteraction(m_levels->getMerchant()->getMerchant(), keyboardKey,
                        [this] { m_menu->changeScreenNormal(Screen::shopMain); }).interaction(m_player);

    // Handle interaction with prisoner
    for (Prisoner *prisoner: m_levels->getPrisoner()->getPrisoners()) {
        PrisonerInteraction(prisoner, keyboardKey, m_levels->getMaps(), m_levels->getCurrentLevel()).
                interaction(m_player);
    }

    // Handle interaction with player's mechanic to heal himself
    HealingInteraction(keyboardKey).interaction(m_player);
    delete playerMovement;
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
    // Set the color based on whether any enemy is in range.
    m_levels->isAnyEnemyInRange(m_player)
        ? GlobalSettings::setColor(COLOR_YELLOW)
        : GlobalSettings::setColor(COLOR_DEFAULT);
    std::cout << "[F] Fight" << "\n";
    GlobalSettings::setColor(COLOR_DEFAULT);
    m_levels->isAnyPrisonerInRange(m_player) ||
    (m_levels->getMerchant()->getMerchant() != nullptr && m_levels->getMerchant()->getMerchant()->
     isAnyMerchantInRange(m_player->getPosition()))
        ? GlobalSettings::setColor(COLOR_YELLOW)
        : GlobalSettings::setColor(COLOR_DEFAULT);
    std::cout << "[E] Interact" << "\n";
    GlobalSettings::setColor(COLOR_DEFAULT);
    std::cout << "[H] Use Heal Potion" << "\n";
    GlobalSettings::setColor(COLOR_YELLOW);
    std::cout << "? = Prisoner, ! = Enemy, $ = Merchant" << "\n";
    GlobalSettings::setColor(COLOR_DEFAULT);
}

void Game::displayPlayerProperties() const {
    std::cout << "HP: ";
    GlobalSettings::setColor(COLOR_RED);
    std::cout << m_player->getHp();
    GlobalSettings::setColor(COLOR_DEFAULT);
    std::cout << " / " << m_player->getMaxHp() << "    \n";
    std::cout << "COINS: ";
    GlobalSettings::setColor(COLOR_YELLOW);
    std::cout << m_player->getCoins() << "      \n";
    GlobalSettings::setColor(COLOR_DEFAULT);
    std::cout << "LVL: " << m_player->getLevel() << "      -     " << m_player->getXp() << "/100 XP   \n";
    std::cout << "HEAL POTIONS: ";
    std::cout << m_player->getNumberOfPotions() << "  \n";
    std::cout << "CAVE: " << m_levels->getCurrentLevel() + 1 << " / " << m_levels->getMaps().size() << "   \n\n";
}

Player *Game::initializePlayer() {
    if (m_player == nullptr) {
        m_player = m_playerDirector->createPlayer();
    }
    return m_player;
}
