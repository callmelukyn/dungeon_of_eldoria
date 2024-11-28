#include "application.h"

#include <conio.h>

#include "menu.h"

Application::Application() {
}

Application::~Application() {
}

void Application::run() {
    Menu menu;
    while (running) {
        menu.render();
        const char key = static_cast<char>(_getch()); // Get user input
        if (key == 27 && menu.getCurrentScreen() == Screen::mainMenu) {
            running = false;
        }
        menu.handleInput(key);
    }
}

void Application::shutdown() {
    running = false;
}

