#include <cmath>
#include "Mesh.h"
#include "Settings.h"

#include <fstream>
#include <sstream>

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

int Mesh::index(int face, int faceSize, int i, int j)
{
    return face * faceSize + i * m_resolution + j;
};

void Mesh::GenerateCube(float side)
{
    float h = side * 0.5f;
    int faceSize = m_resolution * m_resolution;
    m_vertices.resize(6 * faceSize);

    

    for (int i = 0; i < m_resolution; i++)
    {
        float u = (float)i / (m_resolution - 1) - 0.5f;
        for (int j = 0; j < m_resolution; j++)
        {
            float v = (float)j / (m_resolution - 1) - 0.5f;

            {
                Vertex& vert = m_vertices[index(0, faceSize, i, j)];
                vert.x = u * side;
                vert.y = v * side;
                vert.z = h;
                vert.nx = 0; 
                vert.ny = 0; 
                vert.nz = 1;
            }

            {
                Vertex& vert = m_vertices[index(1, faceSize, i, j)];
                vert.x = u * side;
                vert.y = v * side;
                vert.z = -h;
                vert.nx = 0; 
                vert.ny = 0; 
                vert.nz = -1;
            }

            {
                Vertex& vert = m_vertices[index(2, faceSize, i, j)];
                vert.x = h;
                vert.y = u * side;
                vert.z = v * side;
                vert.nx = 1; 
                vert.ny = 0; 
                vert.nz = 0;
            }

            {
                Vertex& vert = m_vertices[index(3, faceSize, i, j)];
                vert.x = -h;
                vert.y = u * side;
                vert.z = v * side;
                vert.nx = -1;
                vert.ny = 0;
                vert.nz = 0;
            }

            {
                Vertex& vert = m_vertices[index(4, faceSize, i, j)];
                vert.x = u * side;
                vert.y = h;
                vert.z = v * side;
                vert.nx = 0; 
                vert.ny = 1; 
                vert.nz = 0;
            }

            {
                Vertex& vert = m_vertices[index(5, faceSize, i, j)];
                vert.x = u * side;
                vert.y = -h;
                vert.z = v * side;
                vert.nx = 0; 
                vert.ny = -1; 
                vert.nz = 0;
            }
        }
    }
}

void Mesh::LoadOBJ(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file)
        return;

    std::vector<float> positions;
    std::vector<float> normals;

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        if (type == "v")
        {
            float x, y, z;
            iss >> x >> y >> z;
            positions.push_back(x);
            positions.push_back(y);
            positions.push_back(z);
        }
        else if (type == "vn")
        {
            float x, y, z;
            iss >> x >> y >> z;
            normals.push_back(x);
            normals.push_back(y);
            normals.push_back(z);
        }
    }

    size_t count = positions.size() / 3;
    m_vertices.resize(count);

    for (size_t i = 0; i < count; i++)
    {
        m_vertices[i].x = positions[3 * i];
        m_vertices[i].y = positions[3 * i + 1];
        m_vertices[i].z = positions[3 * i + 2];

        if (i < normals.size() / 3)
        {
            m_vertices[i].nx = normals[3 * i];
            m_vertices[i].ny = normals[3 * i + 1];
            m_vertices[i].nz = normals[3 * i + 2];
        }
        else
        {
            m_vertices[i].nx = 0;
            m_vertices[i].ny = 0;
            m_vertices[i].nz = 1;
        }
    }
}