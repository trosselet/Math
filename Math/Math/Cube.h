#pragma once

#include "Mesh.h"
#include "Settings.h"

namespace Grp1
{

	class Cube : public Mesh
	{
	public:
		Cube(float side, Settings const& settings);
	};

}