#ifndef GAME_H
#define GAME_H
#include "UI/menu.h"
#include "domain/entities/player.h"
#include "map/levels.h"


class Game {
    Player *m_player;
    Menu *m_menu;
    Levels *m_levels;

    void displayMap() const;

    void displayGUI();

    void displayHelp() const;

    void displayPlayerProperties() const;

public:
    Game();

    ~Game();

    void render();

    void handleInputs(char keyboardKey);
};


#endif //GAME_H
