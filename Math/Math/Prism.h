#pragma once
#include "Mesh.h"
#include "Settings.h"

namespace Grp1
{
	class Prism : public Mesh
	{
	public:
		Prism(float width, float height, float depth, Settings const& settings);
	};
}