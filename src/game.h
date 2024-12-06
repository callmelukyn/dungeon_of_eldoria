#ifndef GAME_H
#define GAME_H
#include "menu.h"


class Game {
    Player *m_player;
    Menu *m_menu;
    std::vector<Map *> m_maps;
    int m_currentLevel;

    void displayMap() const;

    void displayGUI();

    void displayHelp() const;

    void displayPlayerProperties() const;

    void loadLevel(int level);

    void nextLevel();

public:
    Game();

    ~Game();

    void render();

    void handleInputs(char key);
};


#endif //GAME_H
