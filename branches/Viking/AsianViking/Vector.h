#ifndef CustomVector
#define CustomVector
#include <Windows.h>
#include <xnamath.h>

struct Vector3
{
	Vector3();

	Vector3& operator=(const Vector3 &_vector3);
	Vector3& operator=(const XMFLOAT3 &_xmFloat3);
	double x;
	double y;
	double z;
};	
struct Vector2
{
	Vector2();
	double x;
	double y;
		
};

#endif