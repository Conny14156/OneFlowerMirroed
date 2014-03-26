#include "Vector.h"
Vector2::Vector2()
{
	x = 0;
	y = 0;
}
Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}
Vector3& Vector3::operator=(const Vector3 &_vector3)
{
	x = _vector3.x;
	y = _vector3.y;
	z = _vector3.z;
	return *this;
}


//*/
