#pragma once
#include <cstdio>
#include <vector>

class Settings;

constexpr float PI = 3.14159265f;

enum class Axis 
{
    X,
    Y,
    Z
};

struct Vertex
{
    void Debug() const { std::printf("[x=%5.2f, y=%5.2f, z=%5.2f]\n", x, y, z); }
    float x;
    float y;
    float z;

    void Rotate(float angle, Axis axis)
    {
		angle = angle * PI / 180.f;
        float c = std::cos(angle);
        float s = std::sin(angle);
        float nx, ny, nz;

        switch (axis)
        {
        case Axis::X:
            nx = x;
            ny = y * c - z * s;
            nz = y * s + z * c;
            break;

        case Axis::Y:
            nx = x * c + z * s;
            ny = y;
            nz = -x * s + z * c;
            break;

        case Axis::Z:
            nx = x * c - y * s;
            ny = x * s + y * c;
            nz = z;
            break;

        default:
            nx = x; 
            ny = y; 
            nz = z;
            break;
        }

        x = nx; 
        y = ny; 
        z = nz;
    }
};

class Mesh
{
    public:
    Mesh(Settings const& settings);
    std::vector<Vertex> const& GetVertices() const { return m_vertices; }
    void GenerateCircle(float radius);
    void GenerateHalfCircle(float radius);
    void GenerateRectangle(float width, float height);
    void GenerateSquare(float side);
    void GenerateTorus(float majorRadius, float minorRadius);
    void Rotate(float angle, Axis axis);
    void Debug() const;

    private:
    void _GenerateSector(float radius, float angle);

    private:
    std::vector<Vertex> m_vertices;
    int m_resolution;
};