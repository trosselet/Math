#pragma once
#include <string>

class Settings
{
public:
    Settings(int argc, char** argv);

    int GetWidth() const { return m_width; }
    int GetHeight() const { return m_height; }
    int GetMeshResolution() const { return m_meshResolution; }

private:
    void ParseArguments(int argc, char** argv);

    int m_width = 100;
    int m_height = 20;
    int m_meshResolution;
};