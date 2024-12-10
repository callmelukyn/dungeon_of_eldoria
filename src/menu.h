//
// Created by Lukyn on 26.11.2024.
//

#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <vector>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "domain/value_objects/screen.h"
#include "Scenes.h"


//TODO Pak nekde prednastavit urcity levely a pridat je do switche v renderu

class Menu {
private:
    int selected;
    Screen m_currentScreen;
    std::vector<Scenes *> m_scenes;
    Scenes *m_scene;

    //Movement
    void navigateMenu(char key, int selectableItemsOnScreenCount);

    void moveUpMenu(char key, int selectableItemsOnScreenCount);

    void moveDownMenu(char key, int selectableItemsOnScreenCount);

    void confirmSelectionMainMenu(char key);

    void confirmSelectionRoleMenu(char key);

    void changeScreen(Screen newScreen, char key);

public:
    Menu();

    ~Menu();

    //Design methods
    void headerMenu() const;

    void smallHeaderMenu() const;

    //Individual screens
    void displayMainMenu() const;

    void displayRoleMenu() const;

    void displayCreditsMenu() const;

    void displayHowToPlay() const;

    Screen getCurrentScreen() const;

    void displayCutscene() const;

    //Functionality
    void handleMenuInput(char key);

    BOOL setFontSize(COORD dwfontSize) const; //TODO Globalni metoda

    COORD fontSize(); //TODO Globalni parametr

    void hideCursor() const; //TODO Globalni metoda
};

#endif //MENU_H
