#include <iostream>
#include <Windows.h>


void ClearConsole()
{
    std::cout << "\x1B[2J";
}

void ShowCursor()
{
    std::cout << "\x1B[?25h";
}

void HideCursor()
{
    std::cout << "\x1B[?25l";
}

void SetCursorStartPos()
{
    std::cout << "\x1B[H";
}

void SetConsoleSize(int width, int height)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD bufferSize;
    bufferSize.X = width;
    bufferSize.Y = height;
    SetConsoleScreenBufferSize(hConsole, bufferSize);

    SMALL_RECT windowSize;
    windowSize.Left = 0;
    windowSize.Top = 0;
    windowSize.Right = width - 1;
    windowSize.Bottom = height - 1;
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}

int main(int argc, char** argv)
{
    ClearConsole();
    SetCursorStartPos();

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    DWORD mode;
    GetConsoleMode(hConsole, &mode);
    SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

    SetConsoleSize(100, 20);

    HideCursor();
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            std::cout << '.';
        }
    }


    ShowCursor();

    return 0;
}