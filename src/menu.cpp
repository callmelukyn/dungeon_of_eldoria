//
// Created by Lukyn on 26.11.2024.
//

#include "menu.h"

#include "application.h"
#include "map/map.h"


Menu::Menu() {
    selected = 0;
    m_currentScreen = Screen::mainMenu;
}

void Menu::changeScreen(const Screen newScreen) {
    m_currentScreen = newScreen;
}

Screen Menu::getCurrentScreen() const {
    return m_currentScreen;
}

void Menu::handleInput(const char key) {
    switch (m_currentScreen) {
        case Screen::mainMenu:
            navigateMenu(key, 3);
            confirmSelectionMainMenu(key);
            break;
        case Screen::roleMenu:
            navigateMenu(key, 3);
            confirmSelectionRoleMenu(key, selected);
            break;
        case Screen::creditsMenu:
            navigateMenu(key, 0);
            if (key == 13) {
                changeScreen(Screen::mainMenu);
            }
            break;
    }
}

void Menu::render() const {
    switch (m_currentScreen) {
        case Screen::mainMenu:
            displayMainMenu();
            break;
        case Screen::roleMenu:
            displayRoleMenu();
            break;
        case Screen::creditsMenu:
            displayCreditsMenu();
            break;
    }
}

void Menu::clearScreen() const {
    system("cls");
}

void Menu::displayMainMenu() const {
    clearScreen();
    std::cout << "=== MENU ===\n";
    switch (selected) {
        case 0:
            std::cout << "- PLAY\n";
            std::cout << "  CREDITS\n";
            std::cout << "  EXIT\n";
            break;
        case 1:
            std::cout << "  PLAY\n";
            std::cout << "- CREDITS\n";
            std::cout << "  EXIT\n";
            break;
        case 2:
            std::cout << "  PLAY\n";
            std::cout << "  CREDITS\n";
            std::cout << "- EXIT\n";
            break;
    }
}

void Menu::displayCreditsMenu() const {
    clearScreen();
    std::cout << "  ---Authors---\n";
    std::cout << "  Lukas Kulhanek\n";
    std::cout << "  Ivo Dubsik\n";
    std::cout << "  Vit Benda\n";
    std::cout << "Press ENTER to go back.\n";
}

void Menu::displayRoleMenu() const {
    clearScreen();
    std::cout << "=== CHOOSE YOUR ROLE ===\n";
    switch (selected) {
        case 0:
            std::cout << "- WARRIOR\n";
            std::cout << "  ARCHER\n";
            std::cout << "  MAGE\n";
            break;
        case 1:
            std::cout << "  WARRIOR\n";
            std::cout << "- ARCHER\n";
            std::cout << "  MAGE\n";
            break;
        case 2:
            std::cout << "  WARRIOR\n";
            std::cout << "  ARCHER\n";
            std::cout << "- MAGE\n";
            break;
    }
}

void Menu::displayMap() const {
    char key;
    while (key != 27) {
        clearScreen();
        //TODO Predpokladam, ze se da udelat refactor do sraček LVL 100. Ale mapu to ted vypíše na Warriorovi
        Map map = Map(10, 20);
        Position someonsesPosition = Position(1, 1);
        map(someonsesPosition) = 'A';
        map.printMap();
        key = _getch();
    }
}


void Menu::moveUpMenu(const char key, const int selectableItemsOnScreen) {
    if (key == 'w' || key == 'W') {
        selected--;
        if (selected < 0) {
            selected = selectableItemsOnScreen - 1;
        }
    }
}

void Menu::moveDownMenu(const char key, const int selectableItemsOnScreen) {
    if (key == 's' || key == 'S') {
        selected++;
        if (selected >= selectableItemsOnScreen) {
            selected = 0;
        }
    }
}

void Menu::confirmSelectionMainMenu(const char key) {
    if (key == 13) {
        switch (selected) {
            case 0:
                changeScreen(Screen::roleMenu);
                break;
            case 1:
                changeScreen(Screen::creditsMenu);
                break;
            case 2:
                //TODO EXIT
                break;
        }
    }
}

void Menu::confirmSelectionRoleMenu(char key, int &selected) {
    if (key == 13) {
        switch (selected) {
            case 0:
                displayMap();
                break;
            case 1:
                //TODO X
                break;
            case 2:
                //TODO X
                break;
        }
    }
}

void Menu::navigateMenu(const char key, const int selectableItemsOnScreen) {
    // START GAME TOGGLE
    moveUpMenu(key, selectableItemsOnScreen);
    moveDownMenu(key, selectableItemsOnScreen);
    if (m_currentScreen != Screen::mainMenu && key == 27) {
        changeScreen(Screen::mainMenu);
    }
}
