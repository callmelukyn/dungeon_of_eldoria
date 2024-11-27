//
// Created by Lukyn on 26.11.2024.
//

#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <conio.h>
#include <stdlib.h>

class Menu {
private:
    int selected;
public:
    Menu();

    void clearScreen() const;

    void displayMainMenu() const;

    void displayDifficultyMenu() const;

    void displayCreditsMenu() const;

    void navigateMenu();


};

#endif //MENU_H
