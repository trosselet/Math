#pragma once
#include <vector>
#include <windows.h>

class Settings;
class Mesh;
struct Vertex;
class Light;




class Screen
{
public:
    Screen(Settings const& settings);
    ~Screen();
    void Display() const;
    void Display(Mesh const& mesh, Light const& light);

private:
    void _ProjectMesh(Mesh const& mesh, Light const& light);
    void _ProjectInCenterScreenSpace(Vertex& vertex);
    void _ProjectInTopLeftScreenSpace(Vertex& vertex);
    bool _IsVertexInScreen(int u, int v);
    
    static DWORD WINAPI sProjectMeshThread(LPVOID param);

private:
    int m_width;
    int m_height;
    float m_zPosition;
    char m_background;
    char m_meshProjection;
    float m_meshZPosition;
    std::vector<char> m_pixels;
    std::vector<float> m_oozBuffer;

    CRITICAL_SECTION m_cs;
};

struct ThreadData
{
    Screen* pScreen = nullptr;
    Mesh const* pMesh = nullptr;
    Light const* pLight = nullptr;
    unsigned int start = 0;
    unsigned int end = 0;
};