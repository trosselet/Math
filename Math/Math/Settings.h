#pragma once
class Settings
{
public:
    Settings(int argc, char** argv);
    int GetScreenWidth() const { return m_screenWidth; }
    int GetScreenHeight() const { return m_screenHeight; }
    int GetMeshResolution() const { return m_meshResolution; }

private:
    void _ParseArguments(int argc, char** argv);

private:
    int m_screenWidth;
    int m_screenHeight;
    int m_meshResolution;
};