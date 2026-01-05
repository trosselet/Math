#include "HalfCircle.h"

using namespace Grp1;

HalfCircle::HalfCircle(float radius, Settings const& settings) : Mesh(settings)
{
	_GenerateSector(radius, PI);
}
