#pragma once
#include "Settings.h"

#include <cmath>

struct Light
{
    float lx, ly, lz;
    Light(Settings const& settings)
        : lx(settings.GetLightDirectionX()),
        ly(settings.GetLightDirectionY()),
        lz(settings.GetLightDirectionZ())
    {
        float norm = std::sqrt(lx * lx + ly * ly + lz * lz);

        if (norm == 0)
            return;

        lx /= norm;
        ly /= norm;
        lz /= norm;
    }
};
