//
// Created by Lukyn on 26.11.2024.
//

#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <vector>
#include <conio.h>
#include "domain/value_objects/screen.h"
#include "Scenes.h"
#include "domain/value_objects/role.h"


//TODO Pak nekde prednastavit urcity levely a pridat je do switche v renderu

class Menu {
private:
    int selected;
    Screen m_currentScreen;
    std::vector<Scenes *> m_scenes;
    Scenes *m_scene;
    Role m_role;

    //Movement
    void navigateMenu(char keyboardKey, int selectableItemsOnScreenCount);

    void moveUpMenu(char keyboardKey, int selectableItemsOnScreenCount);

    void moveDownMenu(char keyboardKey, int selectableItemsOnScreenCount);

    void confirmSelectionMainMenu(char keyboardKey);

    void confirmSelectionRoleMenu(char keyboardKey);

    void changeScreen(Screen newScreen, char keyboardKey);

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
    void handleMenuInput(char keyboardKey);

    Role getRole() const;
};

#endif //MENU_H
