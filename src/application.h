#ifndef APPLICATION_H
#define APPLICATION_H


class Application {
public:
    Application();

    ~Application();

    void run();

private:
    bool running = true;

    void shutdown();
};


#endif //APPLICATION_H
