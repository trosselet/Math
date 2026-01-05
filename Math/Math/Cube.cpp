#include "Cube.h"

using namespace Grp1;

Cube::Cube(float side, Settings const& settings) : Mesh(settings)
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
