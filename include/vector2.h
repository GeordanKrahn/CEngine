//This class represents a 2D vector, i.e. [Vx Vy]
#pragma once
#include <iostream>
#include <ostream>
#include <math.h>
#include <memory>
#include "../include/vector3.h"

namespace Engine
{
	namespace Mathematics
	{
		class Vector2
		{
		private:
			std::unique_ptr<double> _x;
			std::unique_ptr<double> _y;
		public:
			const double& x = *_x;
			const double& y = *_y;
			void SetX(const double& x) { *_x = x; }
			void SetY(const double& y) { *_y = y; }
			// constructors
			Vector2() : _x(new double(0)), _y(new double(0)) {}
			Vector2(const double& x, const double& y) : _x(new double(x)), _y(new double(y)) {}
			Vector2(const Vector2& v) : _x(new double(v.x)), _y(new double(v.y)) {}
			// assignment overload
			Vector2 operator =(const Vector2& v) { return Vector2(v); }
			//methods
			double Magnitude() const;
			static double DotProduct(const Vector2& a, const Vector2& b) { return (a.x * b.x) + (a.y * b.y); }
			double AngleBetweenVectors(const Vector2& v);
			void Normalize();
			//member operator overloads
			Vector2 operator +(const Vector2& v) {	return Vector2(x + v.x, y + v.y); }
			Vector2 operator -(const Vector2& v) { return Vector2(x - v.x, y - v.y); }
			Vector2 operator *(const double& s) { return Vector2(x * s, y * s); }
			Vector3 ToVector3() const { return Vector3(x, y, 0); }
		};
		//non member operator overloads
		Vector2 operator *(const double& a, const Vector2& b) { return Vector2(a * b.x, a * b.y); }
		bool operator ==(const Vector2& a, const Vector2& b);
		bool operator !=(const Vector2& a, const Vector2& b);
		// Left shift operator for cout compatibility
		std::ostream& operator <<(std::ostream& cout, const Vector2& v);
	}
}