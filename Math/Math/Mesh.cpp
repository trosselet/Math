#include <cmath>
#include "Mesh.h"
#include "Settings.h"

using namespace Grp1;

Mesh::Mesh(Settings const& settings)
: m_resolution(settings.GetMeshResolution())
{
}
 
void Mesh::Rotate(float angle, Axis axis)
{
    for(Vertex& vertex : m_vertices)
    {
        vertex.Rotate(angle, axis);
	}
}

void Mesh::Debug() const
{
    for(Vertex const& vertex : m_vertices)
    {
        vertex.Debug();
    }
}

void Mesh::_GenerateSector(float radius, float angle)
{
    m_vertices.resize(m_resolution * m_resolution);
    for(int i = 0; i < m_resolution; i++)
    {
        float r = (radius * i) / (m_resolution - 1);
        for(int j = 0; j < m_resolution; j++)
        {
            float theta = (angle * j) / (m_resolution - 1);
            m_vertices[m_resolution * i + j].x = r * std::cos(theta);
            m_vertices[m_resolution * i + j].y = r * std::sin(theta);
            m_vertices[m_resolution * i + j].z = 0.f;

            m_vertices[m_resolution * i + j].nx = std::cos(theta);
            m_vertices[m_resolution * i + j].ny = std::sin(theta);
            m_vertices[m_resolution * i + j].nz = 0.f;
        }
    }
}

int Mesh::index(int face, int faceSize, int i, int j)
{
    return face * faceSize + i * m_resolution + j;
};