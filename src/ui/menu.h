//
// Created by Lukyn on 26.11.2024.
//

#ifndef MENU_H
#define MENU_H
#include "../domain/value_objects/screen.h"
#include "scenes.h"
#include "shop.h"
#include "../domain/entities/playerBuilder/playerDirector.h"


class Menu {
    int m_selected;
    Screen m_currentScreen;
    Scenes *m_scene;
    Shop *m_shop;
    PlayerDirector *m_playerDirector;


    //Movement
    void navigateMenu(char keyboardKey, int selectableItemsOnScreenCount);

    void moveUpMenu(char keyboardKey, int selectableItemsOnScreenCount);

    void moveDownMenu(char keyboardKey, int selectableItemsOnScreenCount);

    void confirmSelectionMainMenu(char keyboardKey);

    void confirmSelectionRoleMenu(char keyboardKey);

    void confirmCutscene(char keyboardKey);

    void changeScreen(Screen newScreen, char keyboardKey);

public:
    Menu();

    ~Menu();

    void changeScreenNormal(Screen newScreen);

    //Design methods
    void headerMenu() const;

    void smallHeaderMenu() const;

    //Individual screens
    void displayMainMenu() const;

    void displayRoleMenu() const;

    void displayCreditsMenu() const;

    void displayHowToPlay() const;

    void displayCutscenes() const;

    Screen getCurrentScreen() const;

    //Functionality
    void handleMenuInput(char keyboardKey, Player *player);

    Shop *getShop() const;

    PlayerDirector *getPlayerDirector() const;

    int getSelected() const;
};

#endif //MENU_H
