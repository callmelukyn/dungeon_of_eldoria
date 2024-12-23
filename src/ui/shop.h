//
// Created by Lukyn on 14.12.2024.
//

#ifndef SHOP_H
#define SHOP_H
#include <functional>

#include "scenes.h"
#include "../tools/globalSettings.h"


enum class Screen;

class Shop {
    Scenes *m_scene;
    std::function<void()> m_changeScreenCallback;

public:
    void confirmSelectionShopMain(char keyboardKey, int selected);

    void confirmSelectionShopWeapons(char keyboardKey, int selected);

    void confirmSelectionShopArmor(char keyboardKey, int selected);

    void confirmSelectionShopPotions(char keyboardKey, int selected);

    void changeScreen(const Screen newScreen, const char keyboardKey);

    Shop(std::function<void()> changeScreenCallback);

    ~Shop();

    //Individual screens
    void displayShopHeader() const;

    void displayShopMain(int selected) const;

    void displayShopWeapons(int selected) const;

    void displayShopArmor(int selected) const;

    void displayShopPotions(int selected) const;
};


#endif //SHOP_H
