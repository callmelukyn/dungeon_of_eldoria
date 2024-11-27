//
// Created by Lukyn on 26.11.2024.
//

#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

class Menu {
private:
    int selected;

public:
    Menu();

    //Functionality
    void clearScreen() const;

    void displayMainMenu() const;

    //Individual screens
    void displayRoleMenu();

    void displayCreditsMenu() const;

    //Movement
    void navigateMenu();

    void moveUpMenu(char key, int maxMenuItems);

    void moveDownMenu(char key, int maxMenuItems);

    void confirmSelectionMenu(char key, int &selected);
};

#endif //MENU_H
