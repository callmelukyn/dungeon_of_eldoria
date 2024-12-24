//
// Created by Lukyn on 14.12.2024.
//

#include "shop.h"

#include "../domain/value_objects/screen.h"

Shop::Shop(const std::function<void(Screen screen, char keyboardKey)> &changeScreenCallback) {
    m_scene = new Scenes();
    m_changeScreenCallback = changeScreenCallback;
}

Shop::~Shop() {
    delete m_scene;
}

//Functionality
void Shop::changeScreen(const Screen newScreen, const char keyboardKey) {
    m_changeScreenCallback(newScreen, keyboardKey);

    /*if (m_currentScreen != Screen::shopMain && keyboardKey == KEYBOARD_ESC) {
        GlobalSettings::clearConsoleOnNewScreen();
        m_selected = 0;
        m_currentScreen = Screen::shopMain;
    } else if (keyboardKey == KEYBOARD_ENTER && m_currentScreen != Screen::game) {
        GlobalSettings::clearConsoleOnNewScreen();
        m_currentScreen = newScreen;
    }*/
}

void Shop::confirmSelectionShopMain(const char keyboardKey, int selected) {
    switch (selected) {
        case 0:
            changeScreen(Screen::shopWeapons, keyboardKey);
            break;
        case 1:
            changeScreen(Screen::shopArmor, keyboardKey);
            break;
        case 2:
            changeScreen(Screen::shopPotions, keyboardKey);
            break;
        case 3:
            if (keyboardKey == KEYBOARD_ENTER) {
                changeScreen(Screen::game, keyboardKey);
            }
            break;
        default: break;
    }
}

void Shop::confirmSelectionShopWeapons(char keyboardKey, int selected) {
    switch (selected) {
        case 0:
            //TODO IMPLEMENTACE
            break;
        case 1:
            //TODO IMPLEMENTACE
            break;
        case 2:
            //TODO IMPLEMENTACE
            break;
        default: break;
    }
}

void Shop::confirmSelectionShopArmor(char keyboardKey, int selected) {
    switch (selected) {
        case 0:
            //TODO IMPLEMENTACE
            break;
        case 1:
            //TODO IMPLEMENTACE
            break;
        case 2:
            //TODO IMPLEMENTACE
            break;
        default: break;
    }
}

void Shop::confirmSelectionShopPotions(char keyboardKey, int selected) {
    switch (selected) {
        case 2:
            //TODO IMPLEMENTACE
            break;
        default: break;
    }
}

//Scenes
void Shop::displayShopHeader() const {
    m_scene->sceneShopHeader();
}

void Shop::displayShopWeaponHeader(Player *player) const {
    m_scene->sceneShopWeaponHeader(player);
}

void Shop::displayShopArmorHeader(Player *player) const {
    m_scene->sceneShopArmorHeader(player);
}

void Shop::displayShopPotionHeader(Player *player) const {
    m_scene->sceneShopPotionHeader(player);
}

void Shop::displayShopHint() const {
    m_scene->sceneShopHint();
}

void Shop::displayShopMain(int selected) const {
    displayShopHeader();
    switch (selected) {
        case 0:
            m_scene->sceneShopMainSelectedWeapons();
            break;
        case 1:
            m_scene->sceneShopMainSelectedArmor();
            break;
        case 2:
            m_scene->sceneShopMainSelectedPotions();
            break;
        case 3:
            m_scene->sceneShopMainSelectedExit();
            break;
        default: break;
    }
    displayShopHint();
}

void Shop::displayShopWeapons(int selected, Player *player) const {
    displayShopWeaponHeader(player);
    switch (selected) {
        case 0:
            m_scene->sceneShopWeaponsSelectedWeapon1(player);
            break;
        case 1:
            m_scene->sceneShopWeaponsSelectedWeapon2(player);
            break;
        case 2:
            m_scene->sceneShopWeaponsSelectedWeapon3(player);
            break;
        default: break;
    }
}

void Shop::displayShopArmor(int selected, Player *player) const {
    displayShopArmorHeader(player);
    switch (selected) {
        case 0:
            m_scene->sceneShopArmorSelectedArmor1(player);
            break;
        case 1:
            m_scene->sceneShopArmorSelectedArmor2(player);
            break;
        case 2:
            m_scene->sceneShopArmorSelectedArmor3(player);
            break;
        default: break;
    }
}

void Shop::displayShopPotions(int selected, Player *player) const {
    displayShopPotionHeader(player);
    switch (selected) {
        case 2:
            m_scene->sceneShopPotionsSelectedPotion1();
            break;
        default: break;
    }
}
