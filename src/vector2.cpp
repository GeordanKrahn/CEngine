//This class is the implementation of include/vector2.h
// [Vx  Vy]
#include "../include/functions.h"
#include "../include/vector2.h"



namespace Engine
{
	namespace Mathematics
	{
		double Vector2::Magnitude() const 
		{ 
			double mag = sqrt(pow(x, 2) + pow(y, 2));
			return mag != 0 ? mag : 1; // return 1 to avoid possible division by zero errors in Normalize()
		}
		double Vector2::AngleBetweenVectors(const Vector2& v)
		{
			double magA = Magnitude(), magB = v.Magnitude();
			double dot = DotProduct(*this, v);
			return Functions::RadiansToDegrees(acos(dot / (magA * magB)));
		}
		void Vector2::Normalize()
		{
			double mag = Magnitude();
			*_x /= mag;
			*_y /= mag;
		}

		//non member operator overloads
		bool operator ==(const Vector2& a, const Vector2& b)
		{
			return a.x == b.x && a.y == b.y;
		}
		bool operator !=(const Vector2& a, const Vector2& b)
		{
			return a.x != b.x || a.y != b.y;
		}

		// Left shift operator for cout compatibility
		std::ostream& operator <<(std::ostream& cout, const Vector2& v)
		{
			cout << "V[" << v.x << ", " << v.y << "]";
			return cout;
		}
	}
}