#ifndef BoundingBox_HPP
#define BoundingBox_HPP
#include <Core/Vector.h>
namespace Physics
{
	class BoundingBox
	{
	public:
		BoundingBox(float x, float y, int w, int h);
		BoundingBox(Core::Vector2 position, Core::Vector2i size);

		Core::Vector2 position;
		Core::Vector2i size;
		bool intersect(BoundingBox other);
	};
}
#endif