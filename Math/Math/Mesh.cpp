#include "Mesh.h"

Mesh::Mesh(int meshResolution) 
	: m_resolution(meshResolution)
{
}

Mesh::~Mesh()
{
}

void Mesh::Debug()
{
	for (auto& vertex : m_verticies)
	{
		vertex.Debug();
	}
}

void Mesh::Generate2dResolution(float x, float y = 0)
{
	int verticiesSquare = m_verticies.size() * m_verticies.size();

	if (verticiesSquare == m_resolution)
		return;

	if (y == 0)
		y = x;

	int index = 0;

	for (int i = 0; i < m_resolution; i++)
	{
		for (int j = 0; j < m_resolution; j++)
		{
			m_verticies.push_back({ (float)(((2 * i) / (m_resolution - 1)) - 1), (float)(((2 * j) / (m_resolution - 1)) - 1), 0 });
			index++;
		}
	}

	std::cout << "Index: " << index << std::endl;
}

void Mesh::GenerateCircle(float radius)
{
	Generate2dResolution(radius);
}

void Mesh::GenerateSquare(float size)
{
	Generate2dResolution(size);
}

void Mesh::GenerateHalfCircle(float radius)
{
	Generate2dResolution(radius);
}

void Mesh::GenerateRectangle(float width, float height)
{
	Generate2dResolution(width, height);
}

