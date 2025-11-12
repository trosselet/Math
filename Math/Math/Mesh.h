#pragma once
#include <vector>
#include <iostream>

struct Vertex
{
	float x;
	float y;
	float z;

	inline Vertex(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	inline void Debug()
	{
		std::cout << "X: " << x << " Y: " << y << " Z: " << z << std::endl;
	}
};

class Mesh
{
public:
	Mesh(unsigned int meshResolution);
	~Mesh();

	void Debug();

private:
	std::vector<Vertex> m_verticies;
};

