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

int main(int argc, char** argv)
{
    std::cout << "Hello World!\n";

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hConsole, &mode);
    SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

    ClearConsole();

    HideCursor();
    ShowCursor();
    SetCursorStartPos();

    return 0;
}