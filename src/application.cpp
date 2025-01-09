#include "application.h"

#include <conio.h>

#include "tools/global_settings.h"

bool Application::m_running = true;

Application::Application() {
    m_game = new Game();
}

Application::~Application() {
    delete m_game;
}

void Application::run() const {
    GlobalSettings::turnOnSupportForANSI();
    while (m_running) {
        GlobalSettings::clearScreen();
        GlobalSettings::setFontSize();
        GlobalSettings::hideCursor();
        m_game->render();
        const char keyboardKey = static_cast<char>(_getch()); // Get user input
        m_game->handleInputs(keyboardKey);
    }
}

void Application::shutdown() {
    m_running = false;
}
