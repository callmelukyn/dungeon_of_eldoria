#include "application.h"


Application::Application() {
    m_game = Game();
}

Application::~Application() {
}

void Application::run() {
    while (m_running) {
        m_game.render();
        const char key = static_cast<char>(_getch()); // Get user input
        if (key == 27 && m_game.getCurrentScreen() == Screen::mainMenu) {
            m_running = false;
            break;
        }
        m_game.handleGameInput(key);
    }
}

void Application::shutdown() {
    m_running = false;
}


