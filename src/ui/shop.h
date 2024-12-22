//
// Created by Lukyn on 14.12.2024.
//

#ifndef SHOP_H
#define SHOP_H
#include "scenes.h"
#include "../tools/globalSettings.h"


enum class Screen;

class Shop {
    int m_selected;
    Screen m_currentScreen;
    Scenes *m_scene;

    //Movement
    void navigateShop(char keyboardKey, int selectableItemsOnScreenCount);

    void moveUpShop(char keyboardKey, int selectableItemsOnScreenCount);

    void moveDownShop(char keyboardKey, int selectableItemsOnScreenCount);

    void changeScreen(Screen newScreen, char keyboardKey);

    void confirmSelectionShopMain(char keyboardKey);

    void confirmSelectionShopWeapons(char keyboardKey);

    void confirmSelectionShopArmor(char keyboardKey);

    void confirmSelectionShopPotions(char keyboardKey);

public:
    Shop();

    ~Shop();

    //Individual screens
    void displayShopHeader() const;

    void displayShopMain() const;

    void displayShopWeapons() const;

    void displayShopArmor() const;

    void displayShopPotions() const;

    //Functionality
    void handleShopInput(char keyboardKey);

    Screen getCurrentScreen() const;
};


#endif //SHOP_H
