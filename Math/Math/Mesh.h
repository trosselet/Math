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
	Mesh(int meshResolution);
	~Mesh();

	void Debug();

	void GenerateCircle(float radius);
	void GenerateSquare(float size);
	void GenerateHalfCircle(float radius);
	void GenerateRectangle(float width, float height);

private:
	void Generate2dResolution(float x, float y);

private:
	std::vector<Vertex> m_verticies;
	int m_resolution;
};

