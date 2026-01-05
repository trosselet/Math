#pragma once
#include <cstdio>
#include <vector>
#include <string>

#include "Light.h"

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

    float illumination;

    void Rotate(float angle, Axis axis)
    {
        angle = angle * PI / 180.f;
        float s = std::sin(angle);
        float c = std::cos(angle);

        float tx, ty, tz;

        switch (axis)
        {
        case Axis::X:

            ty = y * c - z * s;
            tz = y * s + z * c;
            y = ty;
            z = tz;

            ty = ny * c - nz * s;
            tz = ny * s + nz * c;
            ny = ty;
            nz = tz;
            break;

        case Axis::Y:
            tx = x * c + z * s;
            tz = -x * s + z * c;
            x = tx;
            z = tz;

            tx = nx * c + nz * s;
            tz = -nx * s + nz * c;
            nx = tx;
            nz = tz;
            break;

        case Axis::Z:
            tx = x * c - y * s;
            ty = x * s + y * c;
            x = tx;
            y = ty;

            tx = nx * c - ny * s;
            ty = nx * s + ny * c;
            nx = tx;
            ny = ty;
            break;
        }
    }

    void ComputeIllumination(Light const& light)
    {
        float norm = std::sqrt(nx * nx + ny * ny + nz * nz);

        if (norm == 0)
            return;

        float nnx = nx / norm;
        float nny = ny / norm;
        float nnz = nz / norm;

        float dot = nnx * light.lx + nny * light.ly + nnz * light.lz;

        illumination = (dot > 0.f) ? dot : 0.f;
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
    void GenerateCube(float side);
    void Prism(float width, float height, float depth);
    void LoadOBJ(const std::string& filename);
    void Rotate(float angle, Axis axis);
    void Debug() const;

private:
    void _GenerateSector(float radius, float angle);
    int index(int face, int faceSize, int i, int j);

private:
    std::vector<Vertex> m_vertices;
    int m_resolution;
};