#include "Screen.h"

#include <iostream>

#include "Mesh.h"

Screen::Screen() : m_bufferSize(), m_windowSize()
{
    m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleMode(m_hConsole, &m_mode);
    SetConsoleMode(m_hConsole, m_mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

Screen::~Screen()
{

}

void Screen::ClearConsole()
{
	std::cout << "\x1B[2J";
}

void Screen::ShowCursor()
{
	std::cout << "\x1B[?25h";
}

void Screen::HideCursor()
{
	std::cout << "\x1B[?25l";
}

void Screen::SetCursorStartPos()
{
	std::cout << "\x1B[H";
}

void Screen::Display(char character)
{
    for (int i = 0; i < m_bufferSize.Y; i++)
    {
        for (int j = 0; j < m_bufferSize.X; j++)
        {
            std::cout << character;
        }
        std::cout << std::endl;
    }
}

void Screen::DisplayMesh(Mesh const& mesh)
{

}

void Screen::SetConsoleSize(int width, int height)
{
    m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    m_bufferSize;
    m_bufferSize.X = width;
    m_bufferSize.Y = height;
    SetConsoleScreenBufferSize(m_hConsole, m_bufferSize);

    m_windowSize;
    m_windowSize.Left = 0;
    m_windowSize.Top = 0;
    m_windowSize.Right = width - 1;
    m_windowSize.Bottom = height - 1;
    SetConsoleWindowInfo(m_hConsole, TRUE, &m_windowSize);
}