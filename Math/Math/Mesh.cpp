#include "Mesh.h"

Mesh::Mesh(unsigned int meshResolution)
{
	m_verticies.push_back({ -1, -1, 0 });
	m_verticies.push_back({ -1,  1, 0 });
	m_verticies.push_back({  1, -1, 0 });
	m_verticies.push_back({  1,  1, 0 });
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
