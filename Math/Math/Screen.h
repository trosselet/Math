#pragma once
#include <vector>

class Settings;

class Screen
{
public:
    Screen(Settings const& settings);
    void Display() const;

private:
    int m_width;
    int m_height;
    std::vector<char> m_pixels;
};

