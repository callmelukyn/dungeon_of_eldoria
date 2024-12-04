//
// Created by Lukyn on 26.11.2024.
//

#include "menu.h"

#include "application.h"

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

void Menu::handleMenuInput(const char key) {
    switch (m_currentScreen) {
        case Screen::mainMenu:
            navigateMenu(key, 4);
            confirmSelectionMainMenu(key);
            break;
        case Screen::roleMenu:
            navigateMenu(key, 3);
            confirmSelectionRoleMenu(key);
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
std::cout<<" _____                                              __   "; setColor(04);std::cout << "______ _     _            _       \n";setColor(07);
std::cout<<"|  __ \\                                            / _| "; setColor(04);std::cout <<"|  ____| |   | |          (_)      \n";setColor(07);
std::cout<<"| |  | |_   _ _ __   __ _  ___  ___  _ __     ___ | |_  "; setColor(04);std::cout <<"| |__  | | __| | ___  _ __ _  __ _ \n";setColor(07);
std::cout<<"| |  | | | | | '_ \\ / _` |/ _ \\/ _ \\| '_ \\   / _ \\|  _| "; setColor(04);std::cout <<"|  __| | |/ _` |/ _ \\| '__| |/ _` |\n";setColor(07);
std::cout<<"| |__| | |_| | | | | (_| |  __/ (_) | | | | | (_) | |   "; setColor(04); std::cout <<"| |____| | (_| | (_) | |  | | (_| |\n";setColor(07);
std::cout<<"|_____/ \\__,_|_| |_|\\__, |\\___|\\___/|_| |_|  \\___/|_|   "; setColor(04); std::cout <<"|______|_|\\__,_|\\___/|_|  |_|\\__,_|\n";setColor(07);
std::cout<<"                    __/ |                                                                 \n";
std::cout<<"                   |___/                                                                  \n";
    /*std::cout << "===- Dungeon of ";
    setColor(04);
    std::cout << "ELDORIA";
    setColor(07);
    std::cout << " -===\n";
    std::cout << "\n";
    std::cout << "\n"; */
    //TODO Mozna jeste pouziju jinde - nemazat koment
}

void Menu::displayMainMenu() const {
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
std::cout << "               _   _                    \n";
std::cout << "    /\\        | | | |                   \n";
std::cout << "   /  \\  _   _| |_| |__   ___  _ __ ___ \n";
std::cout << "  / /\\ \\| | | | __| '_ \\ / _ \\| '__/ __|\n";
std::cout << " / ____ \\ |_| | |_| | | | (_) | |  \\__ \\\n";
std::cout << "/_/    \\_\\__,_|\\__|_| |_|\\___/|_|  |___/\n\n";


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
    headerMenu();
    std::cout << "<=== CHOOSE YOUR ROLE ===>\n";
    switch (selected) {
        case 0:
            setColor(112);
            std::cout << "- WARRIOR";
            setColor(07);
            std::cout << "                 /|   ________________\n";
            std::cout << "  ARCHER";
            std::cout << "              O|===|* >________________>\n";
            std::cout << "  MAGE";
            std::cout << "                    \\|\n";
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
            std::cout << "- ARCHER";
            setColor(07);
            std::cout << "          _.-\"/______________________/////\n";
            std::cout << "  MAGE";
            std::cout << "            `'-.\\~~~~~~~~~~~~~~~~~~~~~~\\\\\\\\\\\n";
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "The Archer can attack his enemies from medium range.\n";
            std::cout << "You are able to fight first, but your health and armor are not the strongest.\n";
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "[ESC] Back\n";
            break;
        case 2:
            std::cout << "  WARRIOR";
            std::cout << "           ___________________    . , ; .\n";
            std::cout << "  ARCHER";
            std::cout << "           (___________________|~~~~~X.;' .\n";
            setColor(112);
            std::cout << "- MAGE";
            setColor(07);
            std::cout << "                                     ' `\" ' `\n";
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "The Mage is able to stay in the shadows far away from its targets.\n";
            std::cout << "Unlocks potential to fight from high range, but once the entities gets too close...";
            std::cout << " it might ";
            setColor(04);
            std::cout << "HURT.\n";
            setColor(07);
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "[ESC] Back\n";
            break;
    }
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
                Application::shutdown();
                break;
        }
    }
}

void Menu::confirmSelectionRoleMenu(char key) {
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
