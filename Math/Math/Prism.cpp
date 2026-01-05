#include "Prism.h"

using namespace Grp1;

Prism::Prism(float width, float height, float depth, Settings const& settings) : Mesh(settings)
{
    const float hw = width * 0.5f;
    const float hh = height * 0.5f;
    const float hd = depth * 0.5f;

    const int faceSize = m_resolution * m_resolution;
    m_vertices.resize(6 * faceSize);

    for (int i = 0; i < m_resolution; i++)
    {
        float u = (float)i / (m_resolution - 1) - 0.5f;
        for (int j = 0; j < m_resolution; j++)
        {
            float v = (float)j / (m_resolution - 1) - 0.5f;

            //(+Z)
            {
                Vertex& vert = m_vertices[index(0, faceSize, i, j)];
                vert.x = u * width;
                vert.y = v * height;
                vert.z = +hd;
                vert.nx = 0;
                vert.ny = 0;
                vert.nz = 1;
            }

            //(-Z)
            {
                Vertex& vert = m_vertices[index(1, faceSize, i, j)];
                vert.x = u * width;
                vert.y = v * height;
                vert.z = -hd;
                vert.nx = 0;
                vert.ny = 0;
                vert.nz = -1;
            }

            //(+X)
            {
                Vertex& vert = m_vertices[index(2, faceSize, i, j)];
                vert.x = +hw;
                vert.y = u * height;
                vert.z = v * depth;
                vert.nx = 1;
                vert.ny = 0;
                vert.nz = 0;
            }

            //(-X)
            {
                Vertex& vert = m_vertices[index(3, faceSize, i, j)];
                vert.x = -hw;
                vert.y = u * height;
                vert.z = v * depth;
                vert.nx = -1;
                vert.ny = 0;
                vert.nz = 0;
            }

            //(+Y)
            {
                Vertex& vert = m_vertices[index(4, faceSize, i, j)];
                vert.x = u * width;
                vert.y = +hh;
                vert.z = v * depth;
                vert.nx = 0;
                vert.ny = 1;
                vert.nz = 0;
            }

            //(-Y)
            {
                Vertex& vert = m_vertices[index(5, faceSize, i, j)];
                vert.x = u * width;
                vert.y = -hh;
                vert.z = v * depth;
                vert.nx = 0;
                vert.ny = -1;
                vert.nz = 0;
            }
        }
    }
}
