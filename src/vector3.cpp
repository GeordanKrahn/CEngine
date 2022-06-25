//This class is the implementation of include/vector3.h
// [Vx  Vy  Vz]
#include "../include/functions.h"
#include "../include/vector3.h"
namespace Engine
{
	namespace Mathematics
	{
		double Vector3::Magnitude() const
		{
			double mag = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
			return mag != 0 ? mag : 1; // return 1 to avoid possible division by zero errors in Normalize()
		}
		
		double Vector3::AngleBetweenVectors(const Vector3& v) const
		{
			double magA = Magnitude(), magB = v.Magnitude();
			double dot = DotProduct(*this, v);
			return Functions::RadiansToDegrees(acos(dot / (magA * magB)));
		}
		void Vector3::Normalize()
		{
			double mag = Magnitude();
			*_x /= mag;
			*_y /= mag;
			*_z /= mag;
		}

		//non member operator overloads
		Vector3 operator *(const Vector3& a, const Vector3& b)
		{
			return Vector3(	a.y * b.z - a.z * b.y, 
							a.z * b.x - a.x * b.z,
							a.x * b.y - a.y * b.x);
		}
		bool operator ==(const Vector3& a, const Vector3& b)
		{
			return a.x == b.x && a.y == b.y && a.z == b.z;
		}
		bool operator !=(const Vector3& a, const Vector3& b)
		{
			return a.x != b.x || a.y != b.y || a.z != b.z;
		}
		// Left shift operator for cout compatibility
		std::ostream& operator <<(std::ostream& cout, const Vector3& a)
		{
			cout << "V[" << a.x << ", " << a.y << ", " << a.z << "]";
			return cout;
		}
	}
}