#pragma once

#include "Mesh.h"
#include "Settings.h"

namespace Grp1
{

	class HalfCircle : public Mesh
	{
	public:
		HalfCircle(float radius, Settings const& settings);
	};

}