#include "application.h"


Application::Application() {
    m_menu = Menu();
}

Application::~Application() {
}

void Application::run() {
    while (m_running) {
        m_menu.render();
        const char key = static_cast<char>(_getch()); // Get user input
        if (key == 27 && m_menu.getCurrentScreen() == Screen::mainMenu) {
            m_running = false;
            break;
        }
        m_menu.handleInput(key);
    }
}

void Application::shutdown() {
    m_running = false;
}


