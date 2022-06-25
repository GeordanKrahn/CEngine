//This class is the implementation of include/vector3.h
// [Vx  Vy  Vz]
#include "../include/functions.h"
#include "../include/vector4.h"
namespace Engine
{
	namespace Mathematics
	{
		double Vector4::Magnitude() const
		{
			double mag = sqrt(pow(w, 2) + pow(x, 2) + pow(y, 2) + pow(z, 2));
			return mag != 0 ? mag : 1; // return 1 to avoid possible division by zero errors in Normalize()
		}

		double Vector4::AngleBetweenVectors(const Vector4& v) const
		{
			double magA = Magnitude(), magB = v.Magnitude();
			double dot = DotProduct(*this, v);
			return Functions::RadiansToDegrees(acos(dot / (magA * magB)));
		}
		void Vector4::Normalize()
		{
			double mag = Magnitude();
			*_w /= mag;
			*_x /= mag;
			*_y /= mag;
			*_z /= mag;
		}

		//non member operator overloads
		bool operator ==(const Vector4& a, const Vector4& b)
		{
			return a.w == b.w && a.x == b.x && a.y == b.y && a.z == b.z;
		}
		bool operator !=(const Vector4& a, const Vector4& b)
		{
			return a.w != b.w || a.x != b.x || a.y != b.y || a.z != b.z;
		}
		// Left shift operator for cout compatibility
		std::ostream& operator <<(std::ostream& cout, const Vector4& a)
		{
			cout << "V[" << a.w << ", " << a.x << ", " << a.y << ", " << a.z << "]";
			return cout;
		}
	}
}