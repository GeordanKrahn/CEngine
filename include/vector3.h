//This class represents a vector in 3D space, i.e. [Vx Vy Vz]
#pragma once
#include <iostream>
#include <ostream>
#include <math.h>
#include <memory>

namespace Engine
{
	namespace Mathematics
	{
		class Vector3
		{
		private:
			std::unique_ptr<double> _x;
			std::unique_ptr<double> _y;
			std::unique_ptr<double> _z;
		public:
			const double& x = *_x;
			const double& y = *_y;
			const double& z = *_z;
			void SetX(const double& x) { *_x = x; }
			void SetY(const double& y) { *_y = y; }
			void SetZ(const double& z) { *_z = z; }
			// constructors
			Vector3() : _x(new double(0)), _y(new double(0)), _z(new double(0)) {}
			Vector3(const double& x, const double& y, const double& z) : _x(new double(x)), _y(new double(y)), _z(new double(z)) {}
			Vector3(const Vector3& v) : _x(new double(v.x)), _y(new double(v.y)), _z(new double(v.z)) {}
			// assignment overload
			Vector3 operator =(const Vector3& v) const { return Vector3(v); }
			//methods
			double Magnitude() const;
			static double DotProduct(const Vector3& a, const Vector3& b) { return (a.x * b.x) + (a.y * b.y) + (a.z * b.z); }
			double AngleBetweenVectors(const Vector3& v) const;
			void Normalize();
			//member operator overloads
			Vector3 operator +(const Vector3& v) const { return Vector3(x + v.x, y + v.y, z + v.z); }
			Vector3 operator -(const Vector3& v) const { return Vector3(x - v.x, y - v.y, z - v.z); }
			Vector3 operator *(const double& s) const { return Vector3(x * s, y * s, z * s); }
		};
		//non member operator overloads
		Vector3 operator *(const Vector3& a, const Vector3& b);
		Vector3 operator *(const double& a, const Vector3& b) { return Vector3(a * b.x, a * b.y, a * b.z); }
		bool operator ==(const Vector3& a, const Vector3& b);
		bool operator !=(const Vector3& a, const Vector3& b);
		// Left shift operator for cout compatibility
		std::ostream& operator <<(std::ostream& cout, const Vector3& v);
	}
}