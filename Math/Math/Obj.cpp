#include "Obj.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

using namespace Grp1;

Obj::Obj(const std::string& filename, Settings const& settings) : Mesh(settings)
{
    std::filesystem::path exePath = std::filesystem::current_path();
    std::filesystem::path path = exePath;

    while (!path.empty())
    {
        std::filesystem::path testPath = path / "Assets";

        if (std::filesystem::exists(testPath) && std::filesystem::is_directory(testPath))
        {
            path = testPath / filename;
            break;
        }

        path = path.parent_path();
    }

    if (path.empty())
    {
        return;
    }

    if (!std::filesystem::exists(path))
    {
        std::cout << "OBJ not found" << path << std::endl;
        return;
    }

    std::ifstream file(path);
    if (!file)
    {
        return;
    }

    std::vector<float> positions;
    std::vector<float> normals;

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        if (type == "v")
        {
            float x, y, z;
            iss >> x >> y >> z;
            positions.push_back(x);
            positions.push_back(y);
            positions.push_back(z);
        }
        else if (type == "vn")
        {
            float x, y, z;
            iss >> x >> y >> z;
            normals.push_back(x);
            normals.push_back(y);
            normals.push_back(z);
        }
    }

    size_t count = positions.size() / 3;
    m_vertices.resize(count);

    for (size_t i = 0; i < count; i++)
    {
        m_vertices[i].x = positions[3 * i];
        m_vertices[i].y = positions[3 * i + 1];
        m_vertices[i].z = positions[3 * i + 2];

        if (i < normals.size() / 3)
        {
            m_vertices[i].nx = normals[3 * i];
            m_vertices[i].ny = normals[3 * i + 1];
            m_vertices[i].nz = normals[3 * i + 2];
        }
        else
        {
            m_vertices[i].nx = 0;
            m_vertices[i].ny = 0;
            m_vertices[i].nz = 1;
        }
    }
}
