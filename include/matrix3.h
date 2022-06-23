//This class represents a 3x3 matrix, i.e.,
//     ┌                   ┐
//     | M11    M12    M13 |
//     | M21    M22    M23 |
//     | M31    M32    M33 |
//     └                   ┘
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
		class Matrix_3x3
		{
		private:
			double m[3][3]{ 0 };
			double& _11 = m[0][0], & _12 = m[0][1], & _13 = m[0][2],
				& _21 = m[1][0], & _22 = m[1][1], & _23 = m[1][2],
				& _31 = m[2][0], & _32 = m[2][1], & _33 = m[2][2];
		public:
			const double& m11 = m[0][0], & m12 = m[0][1], & m13 = m[0][2],
				& m21 = m[1][0], & m22 = m[1][1], & m23 = m[1][2],
				& m31 = m[2][0], & m32 = m[2][1], & m33 = m[2][2];
			Matrix_3x3();
			Matrix_3x3(	const double& m11, const double& m12, const double& m13, 
						const double& m21, const double& m22, const double& m23,
						const double& m31, const double& m32, const double& m33);
			Matrix_3x3(const double arr[3][3]);
			Matrix_3x3(const Vector3 arr[3]);
			Matrix_3x3(const Vector3& a, const Vector3& b, const Vector3& c);
			Matrix_3x3(const Matrix_3x3& m);
			static Matrix_3x3 Create2DRotationMatrix(const double& degrees);
			static Matrix_3x3 Create2DTransformationMatrix(const double& shiftX, const double& shiftY, const double& scaleX, const double& scaleY);
			void Identity();
			Matrix_3x3 Transpose() const { return Matrix_3x3(_11, _21, _31, _12, _22, _32, _13, _23, _33); }
			static Matrix_3x3 Transpose(const Matrix_3x3& m) { return m.Transpose(); }
			Matrix_3x3 operator =(const Matrix_3x3& m) const { return Matrix_3x3(m); }
			void SetElement(const int& row, const int& col, const double& val);
			double Determinant() const;
			static double Determinant(const Matrix_3x3& m);
			Matrix_3x3 Inverse() const;
			static Matrix_3x3 Inverse(const Matrix_3x3& m) { return m.Inverse(); }
		};
	}
}