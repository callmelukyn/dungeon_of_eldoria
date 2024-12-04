#include "application.h"

bool Application::m_running = true;

Application::Application() {
    m_game = new Game();
}

Application::~Application() {
    delete m_game;
}

void Application::run() const {
    while (m_running) {
        m_game->render();
        const char key = static_cast<char>(_getch()); // Get user input
        if (key == 27 && m_game->getCurrentScreen() == Screen::mainMenu) {
            shutdown();
            break;
        }
        m_game->handleGameInput(key);
    }
}

void Application::shutdown() {
    m_running = false;
}


