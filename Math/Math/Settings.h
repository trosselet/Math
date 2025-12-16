#pragma once

class Settings
{
public:
    Settings(int argc, char** argv);
    int GetScreenWidth() const { return m_screenWidth; }
    int GetScreenHeight() const { return m_screenHeight; }
    char GetScreenBackground() const { return m_screenBackground; }
    float GetScreenPosition() const { return m_screenPosition; }
    char GetScreenMeshProjection() const { return m_screenMeshProjection; }
    int GetMeshResolution() const { return m_meshResolution; }
    float GetMeshPosition() const { return m_meshPosition; }
    float GetMeshRotationXPerFrame() const { return m_meshRotationXPerFrame; }
    float GetMeshRotationYPerFrame() const { return m_meshRotationYPerFrame; }
    float GetMeshRotationZPerFrame() const { return m_meshRotationZPerFrame; }
    int GetFrameDuration() const { return m_frameDuration; }
    float GetLightDirectionX() const { return m_lightDirectionX; }
    float GetLightDirectionY() const { return m_lightDirectionY; }
    float GetLightDirectionZ() const { return m_lightDirectionZ; }

private:
    void _ParseArguments(int argc, char** argv);

private:
    int m_screenWidth;
    int m_screenHeight;
    char m_screenBackground;
    float m_screenPosition;
    char m_screenMeshProjection;
    int m_meshResolution;
    float m_meshPosition;
    float m_meshRotationXPerFrame;
    float m_meshRotationYPerFrame;
    float m_meshRotationZPerFrame;
    int m_frameDuration;
    float m_lightDirectionX;
    float m_lightDirectionY;
    float m_lightDirectionZ;
};