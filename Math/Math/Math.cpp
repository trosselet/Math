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

    screen.Display('.');

    screen.ShowCursor();
    return 0;
}