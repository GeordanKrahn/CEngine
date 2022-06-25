//This class represents a 4x4 matrix, i.e.,
//     ┌                          ┐
//     | M11    M12    M13    M14 |
//     | M21    M22    M23    M24 |
//     | M31    M32    M33    M34 |
//     | M41    M42    M43    M44 |
//     └                          ┘
#pragma once
#include <iostream>
#include <ostream>
#include <math.h>
#include <memory>
#include "../include/vector4.h"

namespace Engine
{
	namespace Mathematics
	{
		class Matrix_4x4
		{
		private:
			double m[4][4]{ 0 };
			double	& _11 = m[0][0], & _12 = m[0][1], & _13 = m[0][2], & _14 = m[0][3],
					& _21 = m[1][0], & _22 = m[1][1], & _23 = m[1][2], & _24 = m[1][3],
					& _31 = m[2][0], & _32 = m[2][1], & _33 = m[2][2], & _34 = m[2][3],
					& _41 = m[3][0], & _42 = m[3][1], & _43 = m[3][2], & _44 = m[3][3];
		public:
			const double& m11 = m[0][0], & m12 = m[0][1], & m13 = m[0][2], & m14 = m[0][3],
						& m21 = m[1][0], & m22 = m[1][1], & m23 = m[1][2], & m24 = m[1][3],
						& m31 = m[2][0], & m32 = m[2][1], & m33 = m[2][2], & m34 = m[2][3],
						& m41 = m[3][0], & m42 = m[3][1], & m43 = m[3][2], & m44 = m[3][3];
			Matrix_4x4();
			Matrix_4x4(	const double& m11, const double& m12, const double& m13, const double& m14,
						const double& m21, const double& m22, const double& m23, const double& m24,
						const double& m31, const double& m32, const double& m33, const double& m34, 
						const double& m41, const double& m42, const double& m43, const double& m44);
			Matrix_4x4(const double arr[4][4]);
			Matrix_4x4(const Vector4 arr[4]);
			Matrix_4x4(const Vector4& a, const Vector4& b, const Vector4& c, const Vector4& d);
			Matrix_4x4(const Matrix_4x4& m);
			static Matrix_4x4 CreateRollRotationMatrix(const double& degrees);
			static Matrix_4x4 CreatePitchRotationMatrix(const double& degrees);
			static Matrix_4x4 CreateYawRotationMatrix(const double& degrees);
			static Matrix_4x4 Create3DTransformationMatrix(const double& shiftX, const double& shiftY, const double& shiftZ, const double& scaleX, const double& scaleY, const double& scaleZ);
			void Identity();
			Matrix_4x4 Transpose() const { return Matrix_4x4(_11, _21, _31, _41, _12, _22, _32, _42, _13, _23, _33, _43, _14, _24, _34, _44); }
			static Matrix_4x4 Transpose(const Matrix_4x4& m) { return m.Transpose(); }
			Matrix_4x4 operator =(const Matrix_4x4& m) const { return Matrix_4x4(m); }
			void SetElement(const int& row, const int& col, const double& val);
			double Determinant() const;
			static double Determinant(const Matrix_4x4& m);
			Matrix_4x4 Inverse() const;
			static Matrix_4x4 Inverse(const Matrix_4x4& m) { return m.Inverse(); }
		};
	}
}