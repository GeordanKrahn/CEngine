//This class is the implementation of include/vector2.h
// [Vx  Vy]
#include "../include/functions.h"
#include "../include/vector2.h"



namespace Engine
{
	namespace Mathematics
	{
		// Destructor
		Vector2::~Vector2()
		{
			delete _vx;
			_vx = nullptr;
			delete _vy;
			_vy = nullptr;
		}
		double Vector2::Magnitude() const 
		{ 
			double mag = sqrt(pow(vx, 2) + pow(vy, 2));
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
			*_vx /= mag;
			*_vy /= mag;
		}

		//non member operator overloads
		bool operator ==(const Vector2& a, const Vector2& b)
		{
			return a.vx == b.vx && a.vy == b.vy;
		}
		bool operator !=(const Vector2& a, const Vector2& b)
		{
			return a.vx != b.vx || a.vy != b.vy;
		}

		// Left shift operator for cout compatibility
		std::ostream& operator <<(std::ostream& cout, const Vector2& a)
		{
			cout << "V[" << a.vx << ", " << a.vy << "]";
			return cout;
		}
	}
}