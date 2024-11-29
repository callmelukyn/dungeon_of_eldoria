//
// Created by Lukyn on 26.11.2024.
//

#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "map/map.h"
#include "domain/entities/player.h"


enum class Screen { mainMenu, roleMenu, creditsMenu, howToPlayMenu, game };

enum class Levels { level1, level2, level3, level4, level5 };

//TODO Pak nekde prednastavit urcity levely a pridat je do switche v renderu

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

    void headerMenu() const;

    void setColor(int color) const; //TODO Globalni metoda

    BOOL setFontSize(COORD dwfontSize) const; //TODO Globalni metoda

    COORD fontSize(); //TODO Globalni parametr

    void hideCursor() const; //TODO Globalni metoda

    //Individual screens
    void displayMainMenu() const;

    void displayRoleMenu() const;

    void displayCreditsMenu() const;

    void displayHowToPlay() const;

    //GUI sections

    void displayGUI() const;

    void displayPlayerProperties() const;

    void displayMap() const;

    void displayHelp() const;

    //Movement
    void navigateMenu(char key, int selectableItemsOnScreen);

    void moveUpMenu(char key, int selectableItemsOnScreen);

    void moveDownMenu(char key, int selectableItemsOnScreen);

    void confirmSelectionMainMenu(char key);

    void confirmSelectionRoleMenu(char key, int &selected);
};

#endif //MENU_H
