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
            navigateShop(keyboardKey, 3);
            confirmSelectionShopMenu(keyboardKey);
            break;
        case Screen::shopSub:
            navigateShop(keyboardKey, 3);
            confirmSelectionShopMenu(keyboardKey);
            break;
        default: navigateShop(keyboardKey, 3);
    }
}

void Shop::confirmSelectionShopMenu(const char keyboardKey) {
    switch (m_selected) {
        case 0:
            changeScreen(Screen::shopSub, keyboardKey);
            break;
        case 1:
            changeScreen(Screen::shopSub, keyboardKey);
            break;
        case 2:
            if (keyboardKey == KEYBOARD_ENTER) {
                changeScreen(Screen::game, keyboardKey);
            }
            break;
        default: break;
    }
}

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
