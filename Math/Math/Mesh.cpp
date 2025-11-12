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

void Mesh::GenerateCircle(float radius)
{
}

void Mesh::GenerateSquare(float size)
{
	GenerateRectangle(size, size);
}

void Mesh::GenerateHalfCircle(float radius)
{
}

void Mesh::GenerateRectangle(float width, float height)
{
	m_verticies.clear();
	int nx = m_resolution;
	int ny = m_resolution;

	for (int i = 0; i <= nx; ++i)
	{
		float x = -width / 2.f + i * (width / nx);
		for (int j = 0; j <= ny; ++j)
		{
			float y = -height / 2.f + j * (height / ny);
			m_verticies.emplace_back(x, y, 0.f);
		}
	}
}

