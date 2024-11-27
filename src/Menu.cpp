//
// Created by Lukyn on 26.11.2024.
//

#include "Menu.h"

Menu::Menu() {
    selected = 0;
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
    char key;
    while (key != 13) {
        clearScreen();
        std::cout << "  ---Authors---\n";
        std::cout << "  Lukas Kulhanek\n";
        std::cout << "  Ivo Dubsik\n";
        std::cout << "  Vit Benda\n";
        std::cout << "Press ENTER to go back.\n";
        key = getch();
    }
}

void Menu::displayRoleMenu() {
    char key;
    while (key != 27) {
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
        key = getch();
        moveUpMenu(key, selected);
        moveDownMenu(key, selected);
        confirmSelectionMenu(key, selected);
    }
}

void Menu::moveUpMenu(char key, int &selected) {
    if (key == 'w' || key == 'W') {
        switch (selected) {
            case 0:
                selected = 0;
                break;
            case 1:
                selected = 0;
                break;
            case 2:
                selected = 1;
                break;
        }
    }
}

void Menu::moveDownMenu(char key, int &selected) {
    if (key == 's' || key == 'S') {
        switch (selected) {
            case 0:
                selected = 1;
                break;
            case 1:
                selected = 2;
                break;
            case 2:
                selected = 2;
                break;
        }
    }
}

void Menu::confirmSelectionMenu(char key, int &selected) {
    if (key == 13) {
        switch (selected) {
            case 0:
                displayRoleMenu();
                break;
            case 1:
                displayCreditsMenu();
                break;
            case 2:
                //TODO EXIT
                break;
        }
    }
}


void Menu::navigateMenu() {
    char key;
    while (key != 27) {
        //TODO START GAME TOGGLE
        displayMainMenu();
        key = getch();
        moveUpMenu(key, selected);

        moveDownMenu(key, selected);

        confirmSelectionMenu(key, selected);
    }
}
