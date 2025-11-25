#pragma once
#include <vector>

class Settings;
class Mesh;

class Screen
{
public:
    Screen(Settings const& settings);
    void Display() const;
    void Display(Mesh const& mesh);

private:
    void _ProjectInScreenSpace(Mesh const& mesh);

private:
    int m_width;
    int m_height;
    std::vector<char> m_pixels;

    char m_background;
    char m_projection;
    float m_zPosition;
    float m_meshZPosition;
    std::vector<float> m_oozBuffer;
   
};

