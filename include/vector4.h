//This class represents 4D vector [Vw Vx Vy Vz]
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
		class Vector4
		{
		private:
			std::unique_ptr<double> _x;
			std::unique_ptr<double> _y;
			std::unique_ptr<double> _z;
			std::unique_ptr<double> _w;
		public:
			const double& x = *_x;
			const double& y = *_y;
			const double& z = *_z;
			const double& w = *_w;
			void SetX(const double& x) { *_x = x; }
			void SetY(const double& y) { *_y = y; }
			void SetZ(const double& z) { *_z = z; }
			void SetW(const double& w) { *_x = w; }
			// constructors
			Vector4() : _x(new double(0)), _y(new double(0)), _z(new double(0)), _w(new double(1)) {}
			Vector4(const double& x, const double& y, const double& z, const double& w) : _x(new double(x)), _y(new double(y)), _z(new double(z)), _w(new double(w)) {}
			Vector4(const Vector3& v) : _x(new double(v.x)), _y(new double(v.y)), _z(new double(v.z)), _w(new double(1)) {}
			Vector4(const Vector4& v) : _x(new double(v.x)), _y(new double(v.y)), _z(new double(v.z)), _w(new double(v.w)) {}
			// assignment overload
			Vector4 operator =(const Vector4& v) const { return Vector4(v); }
			Vector4 operator =(const Vector3& v) const { return Vector4(v.x, v.y, v.z, 1); }
			//methods
			double Magnitude() const;
			static double DotProduct(const Vector4& a, const Vector4& b) { return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w); }
			double AngleBetweenVectors(const Vector4& v) const;
			void Normalize();
			//member operator overloads
			Vector4 operator +(const Vector4& v) const { return Vector4(x + v.x, y + v.y, z + v.z, w + v.w); }
			Vector4 operator -(const Vector4& v) const { return Vector4(x - v.x, y - v.y, z - v.z, w - v.w); }
			Vector4 operator *(const double& s) const { return Vector4(x * s, y * s, z * s, w * s); }
		};
		//non member operator overloads
		Vector4 operator *(const double& a, const Vector4& b) { return Vector4(a * b.x, a * b.y, a * b.z, a * b.w); }
		bool operator ==(const Vector4& a, const Vector4& b);
		bool operator !=(const Vector4& a, const Vector4& b);
		// Left shift operator for cout compatibility
		std::ostream& operator <<(std::ostream& cout, const Vector4& v);
	}
}