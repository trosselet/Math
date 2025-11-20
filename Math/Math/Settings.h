#pragma once
class Settings
{
public:
    Settings(int argc, char** argv);
    int GetScreenWidth() const { return m_screenWidth; }
    int GetScreenHeight() const { return m_screenHeight; }
    int GetMeshResolution() const { return m_meshResolution; }
    int GetScreenPosition() const { return m_screenPosition; }
    int GetMeshPosition() const { return m_meshPosition; }
    char GetScreenMeshProjection() const { return m_meshProjection; }
    char GetScreenMeshBackground() const { return m_screenBackground; }

private:
    void _ParseArguments(int argc, char** argv);

private:
    int m_screenWidth;
    int m_screenHeight;
    float m_screenPosition;
    int m_meshResolution;
    char m_screenBackground;
    char m_meshProjection;
    float m_meshPosition;
};