#pragma once

#include "Mesh.h"
#include "Settings.h"

namespace Grp1
{
	class Torus : public Mesh
	{
	public:
		Torus(float majorRadius, float minorRadius, Settings const& settings);
	};
}
