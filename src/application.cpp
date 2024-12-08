#include "application.h"
#include <windows.h>

bool Application::m_running = true;

Application::Application() {
    m_game = new Game();
}

Application::~Application() {
    delete m_game;
}

void Application::run() const {
    while (m_running) {
        clearScreen();
        m_game->render();
        const char key = static_cast<char>(_getch()); // Get user input
        m_game->handleInputs(key);
    }
}

void Application::shutdown() {
    m_running = false;
}

void Application::clearScreen() const {
#ifdef _WIN32
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
#else
    system("clear");
#endif
}
