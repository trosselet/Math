#pragma once

#include "Mesh.h"
#include "Settings.h"

namespace Grp1
{

	class Square : public Mesh
	{
	public:
		Square(float side, Settings const& settings);
	};

}