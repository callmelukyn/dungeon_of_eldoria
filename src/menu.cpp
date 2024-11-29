//
// Created by Lukyn on 26.11.2024.
//

#include "menu.h"


Menu::Menu() {
    selected = 0;
    m_currentScreen = Screen::mainMenu;
}

void Menu::changeScreen(const Screen newScreen) {
    m_currentScreen = newScreen;
}

Screen Menu::getCurrentScreen() const {
    return m_currentScreen;
}

void Menu::handleInput(const char key) {
    switch (m_currentScreen) {
        case Screen::mainMenu:
            navigateMenu(key, 4);
            confirmSelectionMainMenu(key);
            break;
        case Screen::roleMenu:
            navigateMenu(key, 3);
            confirmSelectionRoleMenu(key, selected);
            break;
        case Screen::creditsMenu:
            if (key == 27) {
                changeScreen(Screen::mainMenu);
            }
            break;
        case Screen::howToPlayMenu:
            if (key == 27) {
                changeScreen(Screen::mainMenu);
            }
            break;
        case Screen::game:
            //TODO Movement po mapě
            if (key == 27) {
                changeScreen(Screen::mainMenu);
            }
            break;
    }
}

void Menu::render() const {
    switch (m_currentScreen) {
        case Screen::mainMenu:
            displayMainMenu();
            break;
        case Screen::roleMenu:
            displayRoleMenu();
            break;
        case Screen::creditsMenu:
            displayCreditsMenu();
            break;
        case Screen::howToPlayMenu:
            displayHowToPlay();
            break;
        case Screen::game:
            displayGUI();
            break;
    }
}

void Menu::clearScreen() const {
    system("cls");
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
    std::cout << "===- Dungeon of ";
    setColor(04);
    std::cout << "ELDORIA";
    setColor(07);
    std::cout << " -===\n";
    std::cout << "\n";
    std::cout << "\n";
}

void Menu::displayGUI() const {
    clearScreen();
    displayPlayerProperties();
    displayMap();
    displayHelp();
}


void Menu::displayMainMenu() const {
    clearScreen();
    //TODO Tady ty nastavovače fontu,cursoru a picovin pak dat taky někam do globalniho nastaveni hry
    COORD fontSize = {25, 25};
    setFontSize(fontSize);
    hideCursor();
    headerMenu();
    switch (selected) {
        case 0:
            setColor(112);
            std::cout << "- PLAY\n";
            setColor(07);
            std::cout << "  CREDITS\n";
            std::cout << "  HOW TO PLAY\n";
            std::cout << "  EXIT\n";
            break;
        case 1:
            std::cout << "  PLAY\n";
            setColor(112);
            std::cout << "- CREDITS\n";
            setColor(07);
            std::cout << "  HOW TO PLAY\n";
            std::cout << "  EXIT\n";
            break;
        case 2:
            std::cout << "  PLAY\n";
            std::cout << "  CREDITS\n";
            setColor(112);
            std::cout << "- HOW TO PLAY\n";
            setColor(07);
            std::cout << "  EXIT\n";
            break;
        case 3:
            std::cout << "  PLAY\n";
            std::cout << "  CREDITS\n";
            std::cout << "  HOW TO PLAY\n";
            setColor(112);
            std::cout << "- EXIT\n";
            setColor(07);
            break;
    }
}

void Menu::displayCreditsMenu() const {
    clearScreen();
    headerMenu();
    std::cout << "  ---Authors---\n";
    std::cout << "  Lukas Kulhanek\n";
    std::cout << "  Ivo Dubsik\n";
    std::cout << "  Vit Benda\n";
    std::cout << "\n";
    std::cout << "\n";
    setColor(112);
    std::cout << "[ESC] Back\n";
    setColor(07);
}

void Menu::displayHowToPlay() const {
    clearScreen();
    headerMenu();
    std::cout << "  ---HOW TO PLAY---\n";
    std::cout << "XP: x\n";
    std::cout << "Coins: x\n";
    std::cout << "Fights: x\n";
    std::cout << "Merchant: x\n";
    std::cout << "Prisoners: x\n";
    std::cout << "Lore: x\n";
    std::cout << "\n";
    std::cout << "\n";
    setColor(112);
    std::cout << "[ESC] Back\n";
    setColor(07);
}


void Menu::displayRoleMenu() const {
    clearScreen();
    headerMenu();
    std::cout << "<=== CHOOSE YOUR ROLE ===>\n";
    switch (selected) {
        case 0:
            setColor(112);
            std::cout << "- WARRIOR\n";
            setColor(07);
            std::cout << "  ARCHER\n";
            std::cout << "  MAGE\n";
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "The Warrior has to face his enemies from close range.\n";
            std::cout << "Dungeon entities may damage you more often, but your armor is ready for that.\n";
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "[ESC] Back\n";
            break;
        case 1:
            std::cout << "  WARRIOR\n";
            setColor(112);
            std::cout << "- ARCHER\n";
            setColor(07);
            std::cout << "  MAGE\n";
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "The Archer can attack his enemies from medium range.\n";
            std::cout << "You are able to fight first, but your health and armor are not the strongest\n";
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "[ESC] Back\n";
            break;
        case 2:
            std::cout << "  WARRIOR\n";
            std::cout << "  ARCHER\n";
            setColor(112);
            std::cout << "- MAGE\n";
            setColor(07);
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "The Mage is able to stay in the shadows far away from its targets.\n";
            std::cout << "Unlocks potential to fight from high range, but once the entities gets too close...";
            std::cout << " it might ";
            setColor(04);
            std::cout << "HURT\n";
            setColor(07);
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "[ESC] Back\n";
            break;
    }
}

void Menu::displayPlayerProperties() const {
    //TODO Pridat gettery z Playera do coutu
    std::cout << "HP: ";
    setColor(04);
    std::cout << "100";
    setColor(07);
    std::cout << "        COINS: ";
    setColor(06);
    std::cout << "500" << "\n";
    setColor(07);
    std::cout << "XP: 0/100";
    std::cout << "     HEAL POTIONS: ";
    std::cout << "2" << "\n";
}

void Menu::displayHelp() const {
    std::cout << "[WASD] Move around" << "\n";
    std::cout << "[F] Fight" << "\n";
    std::cout << "[E] Interact" << "\n";
    std::cout << "[H] Heal potion" << "\n";
}


void Menu::displayMap() const {
    Map map = Map(15, 25);
    Position someonsesPosition = Position(10, 5);
    map(someonsesPosition) = 'A';
    map.printMap();
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
    if (key == 13) {
        switch (selected) {
            case 0:
                changeScreen(Screen::roleMenu);
                break;
            case 1:
                changeScreen(Screen::creditsMenu);
                break;
            case 2:
                changeScreen(Screen::howToPlayMenu);
                break;
            case 3:
                //   Application::shutdown();  //TODO Fixnout shutdown
                break;
        }
    }
}

void Menu::confirmSelectionRoleMenu(char key, int &selected) {
    if (key == 13) {
        switch (selected) {
            case 0: //TODO Predat informaci o vyberu konkretni classy Player konstruktoru
                changeScreen(Screen::game);
                break;
            case 1:
                //TODO X
                break;
            case 2:
                //TODO X
                break;
        }
    }
}

void Menu::navigateMenu(const char key, const int selectableItemsOnScreenCount) {
    moveUpMenu(key, selectableItemsOnScreenCount);
    moveDownMenu(key, selectableItemsOnScreenCount);
    if (m_currentScreen != Screen::mainMenu && key == 27) {
        changeScreen(Screen::mainMenu);
    }
}
