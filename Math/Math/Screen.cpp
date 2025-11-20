#include <iostream>
#include "Screen.h"
#include "Settings.h"
#include "Mesh.h"

Screen::Screen(Settings const& settings)
    : m_width(settings.GetScreenWidth())
    , m_height(settings.GetScreenHeight())
    , m_background(settings.GetScreenMeshBackground())
    , m_pixels(m_width* m_height, m_background)
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
    int screenPosition = 5;
    int objectScreenWidth = 0;
    int objectScreenHeight = 0;
    int zMesh = 1;

    for (auto& vertex : mesh.GetVertices())
    {
        objectScreenHeight = ((vertex.y * screenPosition) / zMesh) + 10;
        objectScreenWidth = ((vertex.x * screenPosition) / zMesh) + 10;

        int index = 5 * objectScreenHeight + objectScreenWidth;
        m_pixels[index] = m_projection;
    }

    Display();

}

void Screen::_ProjectInScreenSpace(Mesh const& mesh)
{

}
