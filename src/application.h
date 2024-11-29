#ifndef APPLICATION_H
#define APPLICATION_H
#include "menu.h"


class Application {
public:
    Application();

    ~Application();

    void run();

    void shutdown();

private:
    bool m_running = true;

    Menu m_menu;
};


#endif //APPLICATION_H
