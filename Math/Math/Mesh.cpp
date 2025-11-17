#include "Mesh.h"

static constexpr double PI = 3.141592653589793;


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
	GenerateSector(radius, 2 * PI);
}

void Mesh::GenerateSquare(float size)
{
	GenerateRectangle(size, size);
}

void Mesh::GenerateHalfCircle(float radius)
{
	GenerateSector(radius, PI);
}

void Mesh::GenerateRectangle(float width, float height)
{
	m_verticies.clear();
	int nx = m_resolution;
	int ny = m_resolution;

	for (int i = 0; i < nx; ++i)
	{
		float x = -width / 2.f + i * (width / nx);
		for (int j = 0; j <= ny; ++j)
		{
			float y = -height / 2.f + j * (height / ny);
			m_verticies.emplace_back(x, y, 0.f);
		}
	}
}

std::vector<Vertex> const& Mesh::GetVertices() const
{
	return m_verticies;
}

void Mesh::GenerateSector(float radius, float angle)
{
	m_verticies.clear();
	m_verticies.reserve(m_resolution * m_resolution);

	for (int i = 0; i < m_resolution; ++i)
	{
		float r = radius * (static_cast<float>(i) / (m_resolution - 1));

		for (int j = 0; j < m_resolution; ++j)
		{
			float theta = angle * (static_cast<float>(j) / (m_resolution - 1));
			float x = r * std::cos(theta);
			float y = r * std::sin(theta);

			m_verticies.emplace_back(x, y, 0.f);
		}
	}
}


