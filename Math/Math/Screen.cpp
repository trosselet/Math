#include <iostream>
#include "Screen.h"
#include "Settings.h"

Screen::Screen(Settings const& settings)
    : m_width(settings.GetScreenWidth())
    , m_height(settings.GetScreenHeight())
    , m_pixels(m_width* m_height, '.')
{
}

void Screen::Display() const
{
    for (int i = 0; i < m_height; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            std::cout << m_pixels[m_width * i + j];
        }
        std::cout << std::endl;
    }
}