#include <iostream>
#include <windows.h> // For console settings
#include <signal.h>
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
    std::cout << "\x1b[2J\x1b[3J\x1b[H";
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

void OnKill(int signum)
{
    ClearConsole();
    SetCursorVisible(true);
    exit(signum);
}


int main(int argc, char** argv)
{

    signal(SIGINT, OnKill);

    InitConsole();
    ClearConsole();
    SetCursorVisible(false);

    Settings settings(argc, argv);
    Screen screen(settings);
    screen.Display();
    Mesh mesh(settings);    
    
    mesh.GenerateTorus(20.f, 2.f);

    while (true)
    {
        ClearConsole();
        mesh.Rotate(settings.GetMeshRotationXPerFrame(), Axis::X);
        mesh.Rotate(settings.GetMeshRotationYPerFrame(), Axis::Y);
        mesh.Rotate(settings.GetMeshRotationZPerFrame(), Axis::Z);
        screen.Display(mesh);

        std::cout << "\x1b[H";
    }

    SetCursorVisible(true);
    return 0;
}