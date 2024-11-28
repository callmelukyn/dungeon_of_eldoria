#ifndef APPLICATION_H
#define APPLICATION_H
#include <conio.h>


class Application {
public:
    Application();

    ~Application();

    void run();

    void shutdown();

private:
    bool running = true;
};


#endif //APPLICATION_H
