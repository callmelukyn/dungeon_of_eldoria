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

public:
    Shop();

    ~Shop();

    void navigateShop(char keyboardKey, int selectableItemsOnScreenCount);

    void moveUpShop(char keyboardKey, int selectableItemsOnScreenCount);

    void moveDownShop(char keyboardKey, int selectableItemsOnScreenCount);

    void confirmSelectionShopMenu(char keyboardKey);

    void changeScreen(Screen newScreen, char keyboardKey);

    void handleShopInput(char keyboardKey);

    Screen getCurrentScreen() const;
};


#endif //SHOP_H
