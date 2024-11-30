#ifndef GAME_H
#define GAME_H
#include "menu.h"
#include "domain/entities/player.h"


class Game {
    Player m_player;

    Position m_position;

    Menu m_menu;

    void displayMap();

    void displayFirstLevel();

    void displayGUI();

    void displayHelp() const;

    void displayPlayerProperties() const;

public:
    Game();

    void render();

    void handleGameInput(char key);

    Screen getCurrentScreen() const;
};


#endif //GAME_H
