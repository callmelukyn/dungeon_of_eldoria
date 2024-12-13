#ifndef GAME_H
#define GAME_H
#include "ui/menu.h"
#include "domain/entities/player.h"
#include "map/levels.h"

class Game {
    Player *m_player;
    Menu *m_menu;
    Levels *m_levels;

    void displayMap() const;

    void displayGUI() const;

    void displayHelp() const;

    void displayPlayerProperties() const;

    Player *initializePlayer();

public:
    Game();

    ~Game();

    void render();

    void handleInputs(char keyboardKey) const;
};


#endif //GAME_H
