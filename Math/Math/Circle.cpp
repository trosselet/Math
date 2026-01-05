#include "Circle.h"

using namespace Grp1;

Circle::Circle(float radius, Settings const& settings) : Mesh(settings)
{
	_GenerateSector(radius, 2 * PI);
}
