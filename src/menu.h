//
// Created by Lukyn on 26.11.2024.
//

#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>


enum class Screen { mainMenu, roleMenu, creditsMenu, map };

class Menu {
private:
    int selected;

    Screen m_currentScreen;

public:
    Menu();

    void changeScreen(Screen newScreen);

    Screen getCurrentScreen() const;

    //Functionality
    void handleInput(char key);

    void render() const;

    void clearScreen() const;

    //Individual screens
    void displayMainMenu() const;

    void displayRoleMenu() const;

    void displayCreditsMenu() const;

    void displayMap() const;

    //Movement
    void navigateMenu(char key, int selectableItemsOnScreen);

    void moveUpMenu(char key, int selectableItemsOnScreen);

    void moveDownMenu(char key, int selectableItemsOnScreen);

    void confirmSelectionMainMenu(char key);

    void confirmSelectionRoleMenu(char key, int &selected);
};

#endif //MENU_H
