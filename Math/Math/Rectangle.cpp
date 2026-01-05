#include "Rectangle.h"

using namespace Grp1;

Rectangle::Rectangle(float width, float height, Settings const& settings) : Mesh(settings)
{
    m_vertices.resize(m_resolution * m_resolution);
    for (int i = 0; i < m_resolution; i++)
    {
        for (int j = 0; j < m_resolution; j++)
        {
            m_vertices[m_resolution * i + j].x = (1.f * i / (m_resolution - 1) - 0.5f) * width;
            m_vertices[m_resolution * i + j].y = (1.f * j / (m_resolution - 1) - 0.5f) * height;
            m_vertices[m_resolution * i + j].z = 0.f;

            m_vertices[m_resolution * i + j].nx = 0.f;
            m_vertices[m_resolution * i + j].ny = 0.f;
            m_vertices[m_resolution * i + j].nz = -1.f;
        }
    }
}
