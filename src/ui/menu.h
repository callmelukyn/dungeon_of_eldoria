//
// Created by Lukyn on 26.11.2024.
//

#ifndef MENU_H
#define MENU_H
#include "scenes.h"
#include "shop.h"
#include "../domain/entities/player_builder/player_director.h"
#include "../domain/value_objects/screen.h"

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
    explicit Menu(PlayerDirector *playerDirector);

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

    void displayDeathScreen() const;

    Screen getCurrentScreen() const;

    //Functionality
    void handleMenuInput(char keyboardKey, Player *player);

    Shop *getShop() const;

    int getSelected() const;
};

#endif //MENU_H
