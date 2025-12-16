#include <cmath>
#include "Mesh.h"
#include "Settings.h"



Mesh::Mesh(Settings const& settings)
: m_resolution(settings.GetMeshResolution())
{
}

void Mesh::GenerateCircle(float radius)
{
    _GenerateSector(radius, 2 * PI);
}

void Mesh::GenerateHalfCircle(float radius)
{
    _GenerateSector(radius, PI);
}

void Mesh::GenerateRectangle(float width, float height)
{
    m_vertices.resize(m_resolution * m_resolution);
    for(int i = 0; i < m_resolution; i++)
    {
        for(int j = 0; j < m_resolution; j++)
        {
            m_vertices[m_resolution * i + j].x = (1.f*i / (m_resolution - 1) - 0.5f) * width;
            m_vertices[m_resolution * i + j].y = (1.f*j / (m_resolution - 1) - 0.5f) * height;
            m_vertices[m_resolution * i + j].z = 0.f;

            m_vertices[m_resolution * i + j].nx =  0.f;
            m_vertices[m_resolution * i + j].ny =  0.f;
            m_vertices[m_resolution * i + j].nz = -1.f;
        }
    }
}
void Mesh::GenerateSquare(float side)
{
    GenerateRectangle(side, side);
}

void Mesh::GenerateTorus(float majorRadius, float minorRadius)
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