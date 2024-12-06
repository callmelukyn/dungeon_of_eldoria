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
    std::cout << " _____                                              __   ";
    setColor(04);
    std::cout << "______ _     _            _       \n";
    setColor(07);
    std::cout << "|  __ \\                                            / _| ";
    setColor(04);
    std::cout << "|  ____| |   | |          (_)      \n";
    setColor(07);
    std::cout << "| |  | |_   _ _ __   __ _  ___  ___  _ __     ___ | |_  ";
    setColor(04);
    std::cout << "| |__  | | __| | ___  _ __ _  __ _ \n";
    setColor(07);
    std::cout << "| |  | | | | | '_ \\ / _` |/ _ \\/ _ \\| '_ \\   / _ \\|  _| ";
    setColor(04);
    std::cout << "|  __| | |/ _` |/ _ \\| '__| |/ _` |\n";
    setColor(07);
    std::cout << "| |__| | |_| | | | | (_| |  __/ (_) | | | | | (_) | |   ";
    setColor(04);
    std::cout << "| |____| | (_| | (_) | |  | | (_| |\n";
    setColor(07);
    std::cout << "|_____/ \\__,_|_| |_|\\__, |\\___|\\___/|_| |_|  \\___/|_|   ";
    setColor(04);
    std::cout << "|______|_|\\__,_|\\___/|_|  |_|\\__,_|\n";
    setColor(07);
    std::cout << "                    __/ |                                                                 \n";
    std::cout << "                   |___/                                                                  \n";
}

void Menu::smallHeaderMenu() const {
    std::cout << "|=====> Dungeon of ";
    setColor(04);
    std::cout << "ELDORIA";
    setColor(07);
    std::cout << " <=====|\n";
    std::cout << "\n";
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
    std::cout << "/_/    \\_\\__,_|\\__|_| |_|\\___/|_|  |___/\n\n\n";


    std::cout << "          Lukas ";
    setColor(04);
    std::cout << "\"Lukyn\" ";
    setColor(07);
    std::cout << "Kulhanek\n";
    std::cout << "          Ivo ";
    setColor(04);
    std::cout << "\"Gonres\" ";
    setColor(07);
    std::cout << "Dubsik\n";
    std::cout << "          Vit ";
    setColor(04);
    std::cout << "\"SquEEzy\" ";
    setColor(07);
    std::cout << "Benda\n";
    std::cout << "\n\n";
    setColor(112);
    std::cout << "[ESC] Back\n";
    setColor(07);
}

void Menu::displayHowToPlay() const {
    headerMenu();
    std::cout << "  ---->  GAME MANUAL  <----\n";
    setColor(04);
    std::cout << "XP:\n";
    setColor(07);
    std::cout << "- You gain XP by either killing enemies from the darkness or rescuing prisoners of the dungeon.\n";
    std::cout << "- Leveling up will give you an extra amount of damage per each level depending on your class type.\n";
    setColor(04);
    std::cout << "Coins:\n";
    setColor(07);
    std::cout << "- In-game currency which you can obtain by killing enemies or rescuing prisoners.\n";
    std::cout << "- You can spend coins at Merchant.\n";
    setColor(04);
    std::cout << "Merchant:\n";
    setColor(07);
    std::cout << "- Civilian that is available each 3 stages of your journey through the dungeon.\n";
    std::cout << "- Use your coins at Merchant to buy certain type of items, depending on your class type.\n";
    setColor(04);
    std::cout << "Fights:\n";
    setColor(07);
    std::cout << "- You have an ability to fight with each enemy you might run into, and you will... a lot.\n";
    std::cout <<
            "- Your class type will be the key of each fight. Each class has a different range, that he can fight in.\n";
    std::cout << "- Use [F] to fight, if you are in your allowed range. Depending on your class and range, you will\n";
    std::cout << "  have an advantage of 1 or 2 attacks before the enemy will defend itself.\n";
    std::cout << "- Use your attacks wisely, because once they get too close, there is no going back.\n";
    setColor(04);
    std::cout << "Prisoners:\n";
    setColor(07);
    std::cout <<
            "- Civilians, which you can rescue from their cages. They will give you some coins and XP for exchange.\n";
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
                changeScreen(Screen::game);
                break;
            case 2:
                changeScreen(Screen::game);
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
