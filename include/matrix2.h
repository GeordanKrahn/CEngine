//This class represents a 2x2 matrix i.e.,
//     ┌            ┐
//     | M11    M12 |
//     | M21    M22 |
//     └            ┘
#pragma once
#include <iostream>
#include <ostream>
#include <math.h>
#include <memory>
#include "../include/vector2.h"

namespace Engine
{
	namespace Mathematics
	{
		class Matrix_2x2
		{
		private:
			double m[2][2] {0};
			double &_11 = m[0][0], &_12 = m[0][1], &_21 = m[1][0], &_22 = m[1][1];
		public:
			const double& m11 = m[0][0], m12 = m[0][1], m21 = m[1][0], m22 = m[1][1];
			Matrix_2x2();
			Matrix_2x2(const double& m11, const double& m12, const double& m21, const double& m22);
			Matrix_2x2(const double arr[2][2]);
			Matrix_2x2(const Vector2 arr[2]);
			Matrix_2x2(const Vector2& a, const Vector2& b);
			Matrix_2x2(const Matrix_2x2& m);
			Matrix_2x2 Transpose() const { return Matrix_2x2(_11, _21, _12, _22); }
			static Matrix_2x2 Transpose(const Matrix_2x2& m) { return m.Transpose(); }
			Matrix_2x2 operator =(const Matrix_2x2& m) const;
			void SetElement(const int& row, const int& col, const double& val);
			double Determinant() const;
			static double Determinant(const Matrix_2x2& m);
		};
	}
}