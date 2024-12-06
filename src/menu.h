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
#include "domain/value_objects/screen.h"


//TODO Pak nekde prednastavit urcity levely a pridat je do switche v renderu

class Menu {
private:
    int selected;

    //Movement
    void navigateMenu(char key, int selectableItemsOnScreenCount);

    void moveUpMenu(char key, int selectableItemsOnScreenCount);

    void moveDownMenu(char key, int selectableItemsOnScreenCount);

    void confirmSelectionMainMenu(char key);

    void confirmSelectionRoleMenu(char key);

public:
    Menu();

    //TODO Made public for now, FIX LATER
    Screen m_currentScreen;

    //Design methods
    void headerMenu() const;

    void smallHeaderMenu() const;

    //Individual screens
    void displayMainMenu() const;

    void displayRoleMenu() const;

    void displayCreditsMenu() const;

    void displayHowToPlay() const;

    void changeScreen(Screen newScreen);

    Screen getCurrentScreen() const;

    //Functionality
    void handleMenuInput(char key);

    void setColor(int color) const; //TODO Globalni metoda

    BOOL setFontSize(COORD dwfontSize) const; //TODO Globalni metoda

    COORD fontSize(); //TODO Globalni parametr

    void hideCursor() const; //TODO Globalni metoda
};

#endif //MENU_H
