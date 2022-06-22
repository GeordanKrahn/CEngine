//This class represents a 2D vector, i.e. [Vx Vy]
#pragma once
#include <iostream>
#include <ostream>
#include <math.h>

namespace Engine
{
	namespace Mathematics
	{
		class Vector2
		{
		private:
			double* _vx;
			double* _vy;
		public:
			const double& vx = *_vx;
			const double& vy = *_vy;
			void SetX(const double& vx) { *_vx = vx; }
			void SetY(const double& vy) { *_vy = vy; }
			// constructors
			Vector2() : _vx(new double(0)), _vy(new double(0)) {}
			Vector2(const double& X, const double& Y) : _vx(new double(X)), _vy(new double(Y)) {}
			Vector2(const Vector2& b) : _vx(new double(b.vx)), _vy(new double(b.vy)) {}
			// Destructor
			~Vector2();
			// assignment overload
			Vector2 operator =(const Vector2& v) { return Vector2(v); }
			//methods
			double Magnitude() const;
			static double DotProduct(const Vector2& a, const Vector2& b) { return (a.vx * b.vx) + (a.vy * b.vy); }
			double AngleBetweenVectors(const Vector2& v);
			void Normalize();
			//member operator overloads
			Vector2 operator +(const Vector2& v) {	return Vector2(vx + v.vx, vy + v.vy); }
			Vector2 operator -(const Vector2& v) { return Vector2(vx - v.vx, vy - v.vy); }
			Vector2 operator *(const double& s) { return Vector2(vx * s, vy * s); }
		};
		//non member operator overloads
		Vector2 operator *(const double& lh, const Vector2& rh) { return Vector2(lh * rh.vx, lh * rh.vy); }
		bool operator ==(const Vector2& a, const Vector2& b);
		bool operator !=(const Vector2& a, const Vector2& b);
		// Left shift operator for cout compatibility
		std::ostream& operator <<(std::ostream& cout, const Vector2& a);
	}
}