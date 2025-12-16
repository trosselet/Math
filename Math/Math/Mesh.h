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
    void Debug() const { std::printf("[x=%5.2f, y=%5.2f, z=%5.2f]\n [x=%5.2f, y=%5.2f, z=%5.2f]\n", x, y, z, nx, ny, nz); }
    float x;
    float y;
    float z;

    float nx;
    float ny;
    float nz;

    void Rotate(float angle, Axis axis)
    {
		angle = angle * PI / 180.f;
        float c = std::cos(angle);
        float s = std::sin(angle);
        float newx, newy, newz, newnx, newny, newnz;

        switch (axis)
        {
        case Axis::X:
            newx = x;
            newy = y * c - z * s;
            newz = y * s + z * c;
            newnx = x;
            newny = y * c - z * s;
            newnz = y * s + z * c;
            break;

        case Axis::Y:
            newx = x * c + z * s;
            newnx = x * c + z * s;
            newy = y;
            newny = y;
            newz = -x * s + z * c;
            newnz = -x * s + z * c;
            break;

        case Axis::Z:
            newx = x * c - y * s;
            newnx = x * c - y * s;
            newy = x * s + y * c;
            newny = x * s + y * c;
            newz = z;
            newnz = z;
            break;

        default:
            newx = x; 
            newnx = x; 
            newy = y; 
            newny = y; 
            newz = z;
            newnz = z;
            break;
        }

        x = newx; 
        y = newy; 
        z = newz;
        nx = newnx; 
        ny = newny; 
        nz = newnz;
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