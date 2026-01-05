#pragma once

#include "Mesh.h"
#include "Settings.h"

namespace Grp1
{

	class Circle : public Mesh
	{
	public:
		Circle(float radius, Settings const& settings);
	};

}