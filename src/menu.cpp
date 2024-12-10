//
// Created by Lukyn on 26.11.2024.
//

#include "menu.h"
#include "application.h"
#include "color.h"

Menu::Menu() {
    selected = 0;
    m_currentScreen = Screen::mainMenu;
    m_scenes.push_back(new Scenes());
    m_scene = new Scenes();
}

Menu::~Menu() {
    for (Scenes *scene: m_scenes) {
        delete scene;
    }
}

void Menu::changeScreen(const Screen newScreen, const char key) {
    if (m_currentScreen != Screen::mainMenu && key == 27) {
        clearConsoleOnNewScreen();
        m_currentScreen = Screen::mainMenu;
    } else if (key == 13 && m_currentScreen != Screen::game) {
        clearConsoleOnNewScreen();
        m_currentScreen = newScreen;
    }
}

Screen Menu::getCurrentScreen() const {
    return m_currentScreen;
}

void Menu::handleMenuInput(const char key) {
    switch (m_currentScreen) {
        case Screen::mainMenu:
            if (key == 27) {
                Application::shutdown();
                break;
            }
            navigateMenu(key, 4);
            confirmSelectionMainMenu(key);
            break;
        case Screen::roleMenu:
            navigateMenu(key, 3);
            confirmSelectionRoleMenu(key);
            break;
        case Screen::creditsMenu: // NOLINT
            navigateMenu(key, 1);
            break;
        case Screen::howToPlayMenu:
            navigateMenu(key, 1);
            break;
        case Screen::cutscene:
            navigateMenu(key, 1);
            break;
        default: navigateMenu(key, 4);
    }
}

void Menu::setColor(int color) const {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

BOOL Menu::setFontSize(COORD dwfontSize) const {
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX info{sizeof(CONSOLE_FONT_INFOEX)};
    if (!GetCurrentConsoleFontEx(output, false, &info))
        return false;
    info.dwFontSize = dwfontSize;
    return SetCurrentConsoleFontEx(output, false, &info);
}

void Menu::hideCursor() const {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);

    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void Menu::headerMenu() const {
    m_scene->sceneHeaderMenu();
}

void Menu::smallHeaderMenu() const {
    m_scene->sceneSmallHeaderMenu();
}

void Menu::displayMainMenu() const {
    //TODO Tady ty nastavovače fontu,cursoru a picovin pak dat taky někam do globalniho nastaveni hry
    COORD fontSize = {25, 25};

    setFontSize(fontSize);
    hideCursor();
    headerMenu();
    switch (selected) {
        case 0:
            m_scene->sceneMainSelectedPlay();
            break;
        case 1:
            m_scene->sceneMainSelectedCredits();
            break;
        case 2:
            m_scene->sceneMainSelectedHTP();
            break;
        case 3:
            m_scene->sceneMainSelectedExit();
            break;
    }
}

void Menu::displayCreditsMenu() const {
    m_scene->sceneCreditsMenu();
}

void Menu::displayHowToPlay() const {
    headerMenu();
    m_scene->sceneHTPMenu();
}

void Menu::displayRoleMenu() const {
    clearConsoleOnNewScreen();
    headerMenu();
    std::cout << "<=== CHOOSE YOUR ROLE ===>\n";
    switch (selected) {
        case 0:
            m_scene->sceneRoleSelectedWarrior();
            break;
        case 1:
            m_scene->sceneRoleSelectedArcher();
            break;
        case 2:
            m_scene->sceneRoleSelectedMage();
            break;
    }
}

void Menu::displayCutscene() const {
    m_scenes.at(0)->sceneProlog1();
}

void Menu::moveUpMenu(const char key, const int selectableItemsOnScreenCount) {
    if (key == 'w' || key == 'W') {
        selected--;
        if (selected < 0) {
            selected = selectableItemsOnScreenCount - 1;
        }
    }
}

void Menu::moveDownMenu(const char key, const int selectableItemsOnScreenCount) {
    if (key == 's' || key == 'S') {
        selected++;
        if (selected >= selectableItemsOnScreenCount) {
            selected = 0;
        }
    }
}

void Menu::confirmSelectionMainMenu(const char key) {
    switch (selected) {
        case 0:
            changeScreen(Screen::roleMenu, key);
            break;
        case 1:
            changeScreen(Screen::creditsMenu, key);
            break;
        case 2:
            changeScreen(Screen::howToPlayMenu, key);
            break;
        case 3:
            if (key == 13) {
                Application::shutdown();
                break;
            }
        default: break;
    }
}

void Menu::confirmSelectionRoleMenu(const char key) {
    switch (selected) {
        case 0: //TODO Predat informaci o vyberu konkretni classy Player konstruktoru
            changeScreen(Screen::cutscene, key); //Test cutscene
        //changeScreen(Screen::game, key);
            break;
        case 1:
            changeScreen(Screen::game, key);
            break;
        case 2:
            changeScreen(Screen::game, key);
            break;
        default: break;
    }
}

void Menu::navigateMenu(const char key, const int selectableItemsOnScreenCount) {
    moveUpMenu(key, selectableItemsOnScreenCount);
    moveDownMenu(key, selectableItemsOnScreenCount);
    changeScreen(Screen::mainMenu, key);
}
