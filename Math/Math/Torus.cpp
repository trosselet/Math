#include "Torus.h"

using namespace Grp1;

Torus::Torus(float majorRadius, float minorRadius, Settings const& settings) : Mesh(settings)
{
    m_vertices.resize(m_resolution * m_resolution);
    for (int i = 0; i < m_resolution; i++)
    {
        float theta = (2 * PI * i) / (m_resolution - 1);
        for (int j = 0; j < m_resolution; j++)
        {
            float phi = (2 * PI * j) / (m_resolution - 1);
            m_vertices[m_resolution * i + j].x = (majorRadius + minorRadius * std::cos(phi)) * std::cos(theta);
            m_vertices[m_resolution * i + j].y = (majorRadius + minorRadius * std::cos(phi)) * std::sin(theta);
            m_vertices[m_resolution * i + j].z = minorRadius * std::sin(phi);

            m_vertices[m_resolution * i + j].nx = std::cos(phi);
            m_vertices[m_resolution * i + j].ny = std::sin(phi);
            m_vertices[m_resolution * i + j].nz = 0;
        }
    }
}
