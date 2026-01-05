#define _USE_MATH_DEFINES

#include <iostream>
#include <windows.h> // For console settings
#include <signal.h> // To intercept kill ctrl+c
#include <cmath>
#include "Settings.h"
#include "Screen.h"
#include "Mesh.h"
#include "Light.h"

#include "Circle.h"
#include "HalfCircle.h"
#include "Cube.h"
#include "Obj.h"
#include "Prism.h"
#include "Rectangle.h"
#include "Square.h"
#include "Torus.h"


void InitConsole()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hConsole, &mode);
    SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

void SetCursorToHomePosition()
{
    std::cout << "\x1b[H"; // Set cursor pos to "home" position (0,0)
}

void ClearConsole()
{
    std::cout << "\x1b[2J"; // Remove all characters in console
    SetCursorToHomePosition();
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
    Grp1::Cube cube( 32.f, settings);
    
    Light light(settings);

    while (true)
    {
        SetCursorToHomePosition();
        cube.Rotate(settings.GetMeshRotationXPerFrame(), Grp1::Axis::X);
        cube.Rotate(settings.GetMeshRotationYPerFrame(), Grp1::Axis::Y);
        cube.Rotate(settings.GetMeshRotationZPerFrame(), Grp1::Axis::Z);
        screen.Display(cube, light);
    }
    return 0;
}