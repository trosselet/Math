#pragma once

#include <string>

#include "Mesh.h"
#include "Settings.h"

namespace Grp1
{

	class Obj : public Mesh
	{
	public:
		Obj(const std::string& filename, Settings const& settings);
	};

}