#ifndef APPLICATION_H
#define APPLICATION_H
#include "game.h"

class Application {
    bool m_running = true;

    Game m_game;

public:
    Application();

    ~Application();

    void run();

    void shutdown();
};


#endif //APPLICATION_H
