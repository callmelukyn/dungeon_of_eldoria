#include "application.h"

#include <iostream>

Application::Application() {
}

Application::~Application() {
}

void Application::run() {
    while (running) {
        int cislo;
        std::cin >> cislo;
        if (cislo == 1) {
            shutdown();
        }
        if (cislo == 3) {
            std::cout << "ej";
        }
        if (cislo == 2) {
            std::cout << "press any key to exit..." << std::endl;
        }
    }
}

void Application::shutdown() {
    running = false;
}
