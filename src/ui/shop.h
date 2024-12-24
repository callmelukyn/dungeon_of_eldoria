//
// Created by Lukyn on 14.12.2024.
//

#ifndef SHOP_H
#define SHOP_H
#include <functional>

#include "scenes.h"
#include "../tools/globalSettings.h"
#include "../domain/entities/player.h"
#include "../domain/value_objects/screen.h"


class Shop {
    Scenes *m_scene;
    std::function<void(Screen screen, char keyboardKey)> m_changeScreenCallback;

public:
    void confirmSelectionShopMain(char keyboardKey, int selected);

    void confirmSelectionShopWeapons(char keyboardKey, int selected);

    void confirmSelectionShopArmor(char keyboardKey, int selected);

    void confirmSelectionShopPotions(char keyboardKey, int selected);

    void changeScreen(const Screen newScreen, const char keyboardKey);

    Shop(const std::function<void(Screen screen, char keyboardKey)> &changeScreenCallback);

    ~Shop();

    //Individual screens
    void displayShopHeader() const;

    void displayShopWeaponHeader(Player *player) const;

    void displayShopArmorHeader(Player *player) const;

    void displayShopPotionHeader(Player *player) const;

    void displayShopHint() const;

    void displayShopMain(int selected) const;

    void displayShopWeapons(int selected, Player *player) const;

    void displayShopArmor(int selected, Player *player) const;

    void displayShopPotions(int selected, Player *player) const;
};


#endif //SHOP_H
