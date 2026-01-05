#pragma once

#include "Mesh.h"
#include "Settings.h"

namespace Grp1
{

	class Rectangle : public Mesh
	{
	public:
		Rectangle(float width, float height, Settings const& settings);
	};

}
