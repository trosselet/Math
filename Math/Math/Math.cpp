#include <iostream>
#include <string>

#include "Settings.h"
#include "Screen.h"

int main(int argc, char** argv)
{
    Settings settings(argc, argv);
    int width = settings.GetWidth();
    int height = settings.GetHeight();

    Screen screen;

    screen.SetConsoleSize(width, height);
    screen.ClearConsole();
    screen.SetCursorStartPos();

    screen.HideCursor();

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            std::cout << '.';
        }
        std::cout << std::endl;
    }

    screen.ShowCursor();
    return 0;
}