#include "application.h"
#include <windows.h>
#include <cstdlib>

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
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD coordScreen = {0, 0}; // home for the cursor
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;

    // Get the number of character cells in the current buffer.
    if (!GetConsoleScreenBufferInfo(hStdout, &csbi)) {
        return;
    }

    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    // Fill the entire screen with blanks.
    if (!FillConsoleOutputCharacter(hStdout, // Handle to console screen buffer
                                    (TCHAR) ' ', // Character to write to the buffer
                                    dwConSize, // Number of cells to write
                                    coordScreen, // Coordinates of first cell
                                    &cCharsWritten)) // Receive number of characters written
    {
        return;
    }

    // Get the current text attribute.
    if (!GetConsoleScreenBufferInfo(hStdout, &csbi)) {
        return;
    }

    // Set the buffer's attributes accordingly.
    if (!FillConsoleOutputAttribute(hStdout, // Handle to console screen buffer
                                    csbi.wAttributes, // Character attributes to use
                                    dwConSize, // Number of cells to set attribute
                                    coordScreen, // Coordinates of first cell
                                    &cCharsWritten)) // Receive number of characters written
    {
        return;
    }

    // Put the cursor at its home coordinates.
    SetConsoleCursorPosition(hStdout, coordScreen);
#else
    system("clear");
#endif
}
