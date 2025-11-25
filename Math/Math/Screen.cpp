#include <iostream>
#include "Screen.h"
#include "Settings.h"
#include "Mesh.h"

#include <cmath>

Screen::Screen(Settings const& settings)
    : m_width(settings.GetScreenWidth())
    , m_height(settings.GetScreenHeight())
    , m_background(settings.GetScreenMeshBackground())
    , m_pixels(m_width * m_height, m_background)
    , m_meshZPosition(settings.GetMeshPosition())
    , m_projection(settings.GetScreenMeshProjection())
    , m_zPosition(settings.GetScreenPosition())
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

void Screen::Display(Mesh const& mesh)
{
    std::fill(m_pixels.begin(), m_pixels.end(), m_background);

    _ProjectInScreenSpace(mesh);

    Display();
}

void Screen::_ProjectInScreenSpace(Mesh const& mesh)
{
    for (int i = 0; i < mesh.GetVertices().size() * 4; i++)
    {
        m_oozBuffer.push_back(0);
    }

    for (auto vertex : mesh.GetVertices())
    {
        vertex.z += m_meshZPosition;
        if (vertex.z == 0)
            continue;


        vertex.x = m_zPosition * vertex.x / vertex.z;
        vertex.y = m_zPosition * vertex.y / vertex.z;

        vertex.x += m_width / 2;
        vertex.y += m_height / 2;
        
        int u = std::round(vertex.x);
        int v = std::round(vertex.y);

        float ooz = 1.f / vertex.z;


        if (u >= 0 && u < m_width && v >= 0 && v < m_height && ooz > m_oozBuffer[v * m_width + u])
        {
            m_oozBuffer[v * m_width + u] = ooz;
            m_pixels[v * m_width + u] = m_projection;
        }
    }
}
