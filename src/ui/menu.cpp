//
// Created by Lukyn on 26.11.2024.
//

#include "menu.h"

#include <iostream>

#include "../application.h"
#include "../tools/globalSettings.h"

Menu::Menu() {
    m_selected = 0;
    m_currentScreen = Screen::mainMenu;
    m_scenes.push_back(new Scenes());
    m_scene = new Scenes();
    m_role = {};
}

Menu::~Menu() {
    for (Scenes *scene: m_scenes) {
        delete scene;
    }
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
        case Screen::cutscene1:
            if (keyboardKey == KEYBOARD_ENTER) {
                changeScreen(Screen::cutscene2, keyboardKey);
            }
            break;
        case Screen::cutscene2:
            if (keyboardKey == KEYBOARD_ENTER) {
                changeScreen(Screen::cutscene3, keyboardKey);
            }
            break;
        case Screen::cutscene3:
            if (keyboardKey == KEYBOARD_ENTER) {
                changeScreen(Screen::cutscene4, keyboardKey);
            }
            break;
        case Screen::cutscene4:
            if (keyboardKey == KEYBOARD_ENTER) {
                changeScreen(Screen::game, keyboardKey);
            }
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
    GlobalSettings::clearConsoleOnNewScreen();;
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
    }
}

void Menu::displayCutscene1() const {
    m_scene->sceneProlog1();
}

void Menu::displayCutscene2() const {
    m_scene->sceneProlog2();
}

void Menu::displayCutscene3() const {
    m_scene->sceneProlog3();
}

void Menu::displayCutscene4() const {
    m_scene->sceneProlog4();
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
                break;
            }
        default: break;
    }
}

void Menu::confirmSelectionRoleMenu(const char keyboardKey) {
    switch (m_selected) {
        case 0: //TODO Predat informaci o vyberu konkretni classy Player konstruktoru
            m_role = Role::warrior;
            changeScreen(Screen::cutscene1, keyboardKey);
            break;
        case 1:
            m_role = Role::archer;
            changeScreen(Screen::cutscene1, keyboardKey);
            break;
        case 2:
            m_role = Role::mage;
            changeScreen(Screen::cutscene1, keyboardKey);
            break;
        default: break;
    }
}

void Menu::navigateMenu(const char keyboardKey, const int selectableItemsOnScreenCount) {
    moveUpMenu(keyboardKey, selectableItemsOnScreenCount);
    moveDownMenu(keyboardKey, selectableItemsOnScreenCount);
    changeScreen(Screen::mainMenu, keyboardKey);
}

Role Menu::getRole() const {
    return m_role;
}

