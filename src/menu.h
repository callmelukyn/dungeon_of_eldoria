//
// Created by Lukyn on 26.11.2024.
//

#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>


enum class Screen { mainMenu, roleMenu, creditsMenu };

class Menu {
private:
    int selected;

    Screen m_currentScreen;

public:
    Menu();

    void changeScreen(Screen newScreen);

    Screen getCurrentScreen() const;

    void handleInput(char key);

    void render() const;

    //Functionality
    void clearScreen() const;

    void displayMainMenu() const;

    //Individual screens
    void displayRoleMenu() const;

    void displayCreditsMenu() const;

    //Movement
    void navigateMenu(char key, int selectableItemsOnScreen);

    void moveUpMenu(char key, int selectableItemsOnScreen);

    void moveDownMenu(char key, int selectableItemsOnScreen);

    void confirmSelectionMainMenu(char key);

    void confirmSelectionRoleMenu(char key, int &selected);
};

#endif //MENU_H
