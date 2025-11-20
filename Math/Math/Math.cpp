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
    mesh.GenerateRectangle(2.f, 4.f);
    std::cout << "Rectangle 2x4:" << std::endl;
    mesh.Debug();
    mesh.GenerateSquare(6.f);
    std::cout << "Square 6x6:" << std::endl;
    mesh.Debug();
    mesh.GenerateCircle(2.f);
    std::cout << "Circle radius 2:" << std::endl;
    mesh.Debug();
    mesh.GenerateHalfCircle(1.f);
    std::cout << "Half Circle radius 1:" << std::endl;
    mesh.Debug();
    SetCursorVisible(true);
    return 0;
}