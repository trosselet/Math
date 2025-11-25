#include <iostream>
#include <windows.h> // For console settings
#include "Settings.h"
#include "Screen.h"
#include "Mesh.h"

void InitConsole()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hConsole, &mode);
    SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

void ClearConsole()
{
    std::cout << "\x1b[2J"; // Remove all characters in console
    std::cout << "\x1b[H"; // Set cursor pos to "home" position (0,0)
}

void SetCursorVisible(bool visible)
{
    if (visible)
    {
        std::cout << "\x1b[?25h"; // Make cursor visible
    }
    else
    {
        std::cout << "\x1b[?25l"; // Make cursor invisible
    }
}

int main(int argc, char** argv)
{
    InitConsole();
    ClearConsole();
    SetCursorVisible(false);
    Settings settings(argc, argv);
    Screen screen(settings);
    screen.Display();
    Mesh mesh(settings);

    mesh.GenerateRectangle(4, 2);
    screen.Display(mesh);

    SetCursorVisible(true);
    return 0;
}