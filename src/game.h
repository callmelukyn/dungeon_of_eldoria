#ifndef GAME_H
#define GAME_H
#include "domain/entities/enemy.h"
#include "ui/menu.h"
#include "domain/entities/player.h"
#include "map/levels.h"

class Game {
    PlayerDirector *m_playerDirector;
    Menu *m_menu;
    Levels *m_levels;
    Player *m_player;

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
