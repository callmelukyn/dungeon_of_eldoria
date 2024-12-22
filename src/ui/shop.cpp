//
// Created by Lukyn on 14.12.2024.
//

#include "shop.h"

#include "../domain/value_objects/screen.h"

Shop::Shop() {
    m_selected = 0;
    m_currentScreen = Screen::shopMain;
    m_scene = new Scenes();
}

Shop::~Shop() {
    delete m_scene;
}

//Functionality
void Shop::changeScreen(const Screen newScreen, const char keyboardKey) {
    if (m_currentScreen != Screen::shopMain && keyboardKey == KEYBOARD_ESC) {
        GlobalSettings::clearConsoleOnNewScreen();
        m_selected = 0;
        m_currentScreen = Screen::shopMain;
    } else if (keyboardKey == KEYBOARD_ENTER && m_currentScreen != Screen::game) {
        GlobalSettings::clearConsoleOnNewScreen();
        m_currentScreen = newScreen;
    }
}

void Shop::handleShopInput(const char keyboardKey) {
    switch (m_currentScreen) {
        case Screen::shopMain:
            navigateShop(keyboardKey, 4);
            confirmSelectionShopMain(keyboardKey);
            break;
        case Screen::shopWeapons:
            navigateShop(keyboardKey, 3);
            confirmSelectionShopWeapons(keyboardKey);
            break;
        case Screen::shopArmor:
            navigateShop(keyboardKey, 3);
            confirmSelectionShopArmor(keyboardKey);
            break;
        case Screen::shopPotions:
            navigateShop(keyboardKey, 2);
            confirmSelectionShopPotions(keyboardKey);
            break;
        default: navigateShop(keyboardKey, 3);
    }
}

void Shop::confirmSelectionShopMain(const char keyboardKey) {
    switch (m_selected) {
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

void Shop::confirmSelectionShopWeapons(char keyboardKey) {
    switch (m_selected) {
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

void Shop::confirmSelectionShopArmor(char keyboardKey) {
    switch (m_selected) {
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

void Shop::confirmSelectionShopPotions(char keyboardKey) {
    switch (m_selected) {
        case 0:
            //TODO IMPLEMENTACE
            break;
        case 1:
            //TODO IMPLEMENTACE
            break;
        default: break;
    }
}

//Movement
void Shop::navigateShop(char keyboardKey, int selectableItemsOnScreenCount) {
    moveUpShop(keyboardKey, selectableItemsOnScreenCount);
    moveDownShop(keyboardKey, selectableItemsOnScreenCount);
    changeScreen(Screen::shopMain, keyboardKey);
}

void Shop::moveUpShop(const char keyboardKey, const int selectableItemsOnScreenCount) {
    if (keyboardKey == KEYBOARD_SMALL_W || keyboardKey == KEYBOARD_CAPITAL_W) {
        m_selected--;
        if (m_selected < 0) {
            m_selected = selectableItemsOnScreenCount - 1;
        }
    }
}

void Shop::moveDownShop(const char keyboardKey, const int selectableItemsOnScreenCount) {
    if (keyboardKey == KEYBOARD_SMALL_S || keyboardKey == KEYBOARD_CAPITAL_S) {
        m_selected++;
        if (m_selected >= selectableItemsOnScreenCount) {
            m_selected = 0;
        }
    }
}

Screen Shop::getCurrentScreen() const {
    return m_currentScreen;
}

//Scenes
void Shop::displayShopHeader() const {
    m_scene->sceneShopHeader();
}

void Shop::displayShopMain() const {
    displayShopHeader();
    switch (m_selected) {
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
}

void Shop::displayShopWeapons() const {
    switch (m_selected) {
        case 0:
            m_scene->sceneShopWeaponsSelectedWeapon1();
            break;
        case 1:
            m_scene->sceneShopWeaponsSelectedWeapon2();
            break;
        case 2:
            m_scene->sceneShopWeaponsSelectedWeapon3();
            break;
        default: break;
    }
}

void Shop::displayShopArmor() const {
    switch (m_selected) {
        case 0:
            m_scene->sceneShopArmorSelectedArmor1();
            break;
        case 1:
            m_scene->sceneShopArmorSelectedArmor2();
            break;
        case 2:
            m_scene->sceneShopArmorSelectedArmor3();
            break;
        default: break;
    }
}

void Shop::displayShopPotions() const {
    switch (m_selected) {
        case 0:
            m_scene->sceneShopPotionsSelectedPotion1();
            break;
        case 1:
            m_scene->sceneShopPotionsSelectedPotion2();
            break;
        default: break;
    }
}
