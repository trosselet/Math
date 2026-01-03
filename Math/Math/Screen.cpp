#include <iostream>
#include <cmath>
#include "Screen.h"
#include "Settings.h"
#include "Mesh.h"
#include "Light.h"

Screen::Screen(Settings const& settings)
: m_width(settings.GetScreenWidth())
, m_height(settings.GetScreenHeight())
, m_zPosition(settings.GetScreenPosition())
, m_background(settings.GetScreenBackground())
, m_meshProjection(settings.GetScreenMeshProjection())
, m_meshZPosition(settings.GetMeshPosition())
, m_pixels(m_width * m_height, '.')
, m_oozBuffer(m_width * m_height, 0.f)
{
    InitializeCriticalSection(&m_cs);
}

Screen::~Screen()
{
    DeleteCriticalSection(&m_cs);
}

DWORD WINAPI Screen::sProjectMeshThread(LPVOID param)
{
    ThreadData* data = static_cast<ThreadData*>(param);

    auto& verticies = data->pMesh->GetVertices();
    Screen* screen = data->pScreen;

    for (unsigned int i = data->start; i < data->end; i++)
    {
        Vertex vertex = verticies[i];
        screen->_ProjectInCenterScreenSpace(vertex);
        screen->_ProjectInTopLeftScreenSpace(vertex);

        int x = static_cast<int>(std::round(vertex.x));
        int y = static_cast<int>(std::round(vertex.y));

        if (!screen->_IsVertexInScreen(x, y))
        {
            continue;
        }

        float ooz = 1.f / vertex.z;
        vertex.ComputeIllumination(*data->pLight);

        int index = y * screen->m_width + x;

        EnterCriticalSection(&screen->m_cs);

        if (ooz > screen->m_oozBuffer[index])
        {
            screen->m_oozBuffer[index] = ooz;
            screen->m_pixels[index] = ".,-~:;=!*#$@"[(int)(vertex.illumination * 12)];
        }

        LeaveCriticalSection(&screen->m_cs);

    }


    return 0;
}

void Screen::Display() const
{
    for(int i = 0; i < m_height; i++)
    {
        for(int j = 0; j < m_width; j++)
        {
            std::cout << m_pixels[m_width * i + j];
        }
        std::cout << std::endl;
    }
}

void Screen::Display(Mesh const& mesh, Light const& light)
{
    std::fill(m_pixels.begin(), m_pixels.end(), m_background);
    _ProjectMesh(mesh, light);
    Display();
}

void Screen::_ProjectMesh(Mesh const& mesh, Light const& light)
{
    std::fill(m_oozBuffer.begin(), m_oozBuffer.end(), 0.f);
    const auto& verticies = mesh.GetVertices();

    const int threadCount = min(8, static_cast<int>(verticies.size()));
    const int numberOfPart = static_cast<int>(verticies.size()) / threadCount;

    HANDLE threads[8];
    ThreadData data[8];

    for (unsigned int i = 0; i < threadCount; i++)
    {
        unsigned int end = 0;

        if (i == threadCount - 1)
        {
            end = static_cast<unsigned int>(verticies.size());
        }
        else
        {
            end = (i + 1) * numberOfPart;
        }

        data[i] =
        {
            this,
            &mesh,
            &light,
            i * numberOfPart,
            end
        };

        threads[i] = CreateThread(
            nullptr,
            0,
            Screen::sProjectMeshThread,
            &data[i],
            0,
            nullptr
        );

    }

    WaitForMultipleObjects(threadCount, threads, TRUE, INFINITE);

    for (int i = 0; i < threadCount; i++)
    {
        CloseHandle(threads[i]);    
    }

}

void Screen::_ProjectInCenterScreenSpace(Vertex& vertex)
{
    vertex.z += m_meshZPosition;
    vertex.x = m_zPosition * vertex.x / vertex.z;
    vertex.y = m_zPosition * vertex.y / vertex.z / 2.f;
}

void Screen::_ProjectInTopLeftScreenSpace(Vertex& vertex)
{
    vertex.x += m_width / 2;
    vertex.y += m_height / 2;
}

bool Screen::_IsVertexInScreen(int u, int v)
{
    return u >= 0 && u < m_width && v >= 0 && v < m_height;
}