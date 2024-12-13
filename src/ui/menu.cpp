//
// Created by Lukyn on 26.11.2024.
//

#include "menu.h"

#include <iostream>

#include "../application.h"
#include "../domain/entities/playerBuilder/archerBuilder.h"
#include "../domain/entities/playerBuilder/mageBuilder.h"
#include "../domain/entities/playerBuilder/warriorBuilder.h"
#include "../tools/globalSettings.h"

Menu::Menu() {
    m_selected = 0;
    m_currentScreen = Screen::mainMenu;
    m_scene = new Scenes();
    m_playerDirector = new PlayerDirector(nullptr);
}

Menu::~Menu() {
    delete m_scene;
    delete m_playerDirector;
}

void Menu::changeScreen(const Screen newScreen, const char keyboardKey) {
    if (m_currentScreen != Screen::mainMenu && keyboardKey == KEYBOARD_ESC) {
        GlobalSettings::clearConsoleOnNewScreen();
        m_currentScreen = Screen::mainMenu;
    } else if (keyboardKey == KEYBOARD_ENTER && m_currentScreen != Screen::game) {
        GlobalSettings::clearConsoleOnNewScreen();
        m_currentScreen = newScreen;
    }
}

Screen Menu::getCurrentScreen() const {
    return m_currentScreen;
}

void Menu::handleMenuInput(const char keyboardKey) {
    switch (m_currentScreen) {
        case Screen::mainMenu:
            if (keyboardKey == KEYBOARD_ESC) {
                Application::shutdown();
                break;
            }
            navigateMenu(keyboardKey, 4);
            confirmSelectionMainMenu(keyboardKey);
            break;
        case Screen::roleMenu:
            navigateMenu(keyboardKey, 3);
            confirmSelectionRoleMenu(keyboardKey);
            break;
        case Screen::creditsMenu: // NOLINT
            navigateMenu(keyboardKey, 1);
            break;
        case Screen::howToPlayMenu:
            navigateMenu(keyboardKey, 1);
            break;
        case Screen::cutscenes:
            confirmCutscene(keyboardKey);
            break;
        default: navigateMenu(keyboardKey, 4);
    }
}

void Menu::headerMenu() const {
    m_scene->sceneHeaderMenu();
}

void Menu::smallHeaderMenu() const {
    m_scene->sceneSmallHeaderMenu();
}

void Menu::displayMainMenu() const {
    headerMenu();
    switch (m_selected) {
        case 0:
            m_scene->sceneMainSelectedPlay();
            break;
        case 1:
            m_scene->sceneMainSelectedCredits();
            break;
        case 2:
            m_scene->sceneMainSelectedHTP();
            break;
        case 3:
            m_scene->sceneMainSelectedExit();
            break;
        default: break;
    }
}

void Menu::displayCreditsMenu() const {
    m_scene->sceneCreditsMenu();
}

void Menu::displayHowToPlay() const {
    headerMenu();
    m_scene->sceneHTPMenu();
}

void Menu::displayRoleMenu() const {
    GlobalSettings::clearConsoleOnNewScreen();
    headerMenu();
    std::cout << "<=== CHOOSE YOUR ROLE ===>\n";
    switch (m_selected) {
        case 0:
            m_scene->sceneRoleSelectedWarrior();
            break;
        case 1:
            m_scene->sceneRoleSelectedArcher();
            break;
        case 2:
            m_scene->sceneRoleSelectedMage();
            break;
        default: break;
    }
}

void Menu::displayCutscenes() const {
    m_scene->printScenes();
}

void Menu::moveUpMenu(const char keyboardKey, const int selectableItemsOnScreenCount) {
    if (keyboardKey == KEYBOARD_SMALL_W || keyboardKey == KEYBOARD_CAPITAL_W) {
        m_selected--;
        if (m_selected < 0) {
            m_selected = selectableItemsOnScreenCount - 1;
        }
    }
}

void Menu::moveDownMenu(const char keyboardKey, const int selectableItemsOnScreenCount) {
    if (keyboardKey == KEYBOARD_SMALL_S || keyboardKey == KEYBOARD_CAPITAL_S) {
        m_selected++;
        if (m_selected >= selectableItemsOnScreenCount) {
            m_selected = 0;
        }
    }
}

void Menu::confirmSelectionMainMenu(const char keyboardKey) {
    switch (m_selected) {
        case 0:
            changeScreen(Screen::roleMenu, keyboardKey);
            break;
        case 1:
            changeScreen(Screen::creditsMenu, keyboardKey);
            break;
        case 2:
            changeScreen(Screen::howToPlayMenu, keyboardKey);
            break;
        case 3:
            if (keyboardKey == KEYBOARD_ENTER) {
                Application::shutdown();
            }
            break;
        default: break;
    }
}

void Menu::confirmSelectionRoleMenu(const char keyboardKey) {
    switch (m_selected) {
        case 0:
            m_playerDirector->setBuilder(new WarriorBuilder());
            break;
        case 1:
            m_playerDirector->setBuilder(new ArcherBuilder());
            break;
        case 2:
            m_playerDirector->setBuilder(new MageBuilder());
            break;
        default: break;
    }
    changeScreen(Screen::cutscenes, keyboardKey);
}

void Menu::confirmCutscene(const char keyboardKey) {
    if (keyboardKey != KEYBOARD_ENTER) {
        GlobalSettings::clearConsoleOnNewScreen();
    } else {
        GlobalSettings::clearConsoleOnNewScreen();
        m_scene->incrementCurrentScene(keyboardKey);
        if (m_scene->getCurrentScene() > 3) {
            changeScreen(Screen::game, keyboardKey);
            m_scene->setCurrentScene(0);
        }
    }
}

void Menu::navigateMenu(const char keyboardKey, const int selectableItemsOnScreenCount) {
    moveUpMenu(keyboardKey, selectableItemsOnScreenCount);
    moveDownMenu(keyboardKey, selectableItemsOnScreenCount);
    changeScreen(Screen::mainMenu, keyboardKey);
}

PlayerDirector *Menu::getPlayerDirector() const {
    return m_playerDirector;
}

