#ifndef APPLICATION_H
#define APPLICATION_H
#include "game.h"

class Application {
    static bool m_running;
    Game *m_game;

public:
    Application();

    ~Application();

    void run() const;

    static void shutdown();
};


#endif //APPLICATION_H
