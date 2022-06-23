//This class is the implementation if include/matrix3.h
//     ┌                   ┐
//     | M11    M12    M13 |
//     | M21    M22    M23 |
//     | M31    M32    M33 |
//     └                   ┘
#pragma once
#include "../include/functions.h"
#include "../include/matrix2.h"
#include "../include/matrix3.h"
namespace Engine
{
	namespace Mathematics
	{
		Matrix_3x3::Matrix_3x3()
		{
			_11 = 0; _12 = 0; _13 = 0;
			_21 = 0; _22 = 0; _23 = 0;
			_31 = 0; _32 = 0; _33 = 0;
		}

		Matrix_3x3::Matrix_3x3(	const double& m11, const double& m12, const double& m13,
								const double& m21, const double& m22, const double& m23,
								const double& m31, const double& m32, const double& m33)
		{
			_11 = m11; _12 = m12; _13 = m13;
			_21 = m21; _22 = m22; _23 = m23;
			_31 = m31; _32 = m32; _33 = m33;
		}

		Matrix_3x3::Matrix_3x3(const double arr[3][3])
		{
			_11 = arr[0][0]; _12 = arr[0][1]; _13 = arr[0][2];
			_21 = arr[1][0]; _22 = arr[1][1]; _23 = arr[1][2];
			_31 = arr[2][0]; _32 = arr[2][1]; _33 = arr[2][2];
		}

		Matrix_3x3::Matrix_3x3(const Vector3 arr[3])
		{
			_11 = arr[0].x; _12 = arr[1].x; _13 = arr[2].x;
			_21 = arr[0].y; _22 = arr[1].y; _23 = arr[2].y;
			_31 = arr[0].z; _32 = arr[1].z; _33 = arr[2].z;
		}

		Matrix_3x3::Matrix_3x3(const Vector3& a, const Vector3& b, const Vector3& c)
		{
			_11 = a.x; _12 = b.x; _13 = c.x;
			_21 = a.y; _22 = b.y; _23 = c.y;
			_31 = a.z; _32 = b.z; _33 = c.z;
		}

		Matrix_3x3::Matrix_3x3(const Matrix_3x3& m)
		{
			_11 = m.m11; _12 = m.m12; _13 = m.m13;
			_21 = m.m21; _22 = m.m22; _23 = m.m23;
			_31 = m.m31; _32 = m.m32; _33 = m.m33;
		}

		Matrix_3x3 Matrix_3x3::Create2DRotationMatrix(const double& degrees)
		{
			return Matrix_3x3(	cos(Functions::DegreesToRadians(degrees)), -sin(Functions::DegreesToRadians(degrees)),	0,
								sin(Functions::DegreesToRadians(degrees)), cos(Functions::DegreesToRadians(degrees)),	0,
								0,										   0,											1);
		}
		Matrix_3x3 Matrix_3x3::Create2DTransformationMatrix(const double& shiftX, const double& shiftY, const double& scaleX, const double& scaleY)
		{
			return Matrix_3x3(	scaleX,	0,		shiftX,
								0,		scaleY, shiftY,
								0,		0,		1);
		}

		void Matrix_3x3::Identity()
		{
			_11 = 1; _12 = 0; _13 = 0;
			_21 = 0; _22 = 1; _23 = 0;
			_31 = 0; _32 = 0; _33 = 1;
		}

		void Matrix_3x3::SetElement(const int& row, const int& col, const double& val)
		{
			if (!(row > 3 || row < 1 || col > 3 || col < 1)) { m[row - 1][col - 1] = val; }
		}
		double Matrix_3x3::Determinant() const 
		{ 
			return (_11 * Matrix_2x2(_22, _23, _32, _33).Determinant() -
					_12 * Matrix_2x2(_21, _23, _31, _33).Determinant() +
					_13 * Matrix_2x2(_21, _22, _31, _32).Determinant());
		}
		double Matrix_3x3::Determinant(const Matrix_3x3& m) { return m.Determinant(); }
		Matrix_3x3 Matrix_3x3::Inverse() const
		{
			double det = Determinant();
			return Matrix_3x3(	Matrix_2x2(_22, _23, _32, _33).Determinant() / det, 
								-Matrix_2x2(_21, _23, _31, _33).Determinant() / det,
								Matrix_2x2(_21, _22, _31, _32).Determinant() / det,
								-Matrix_2x2(_12, _13, _32, _33).Determinant() / det,
								Matrix_2x2(_11, _13, _31, _33).Determinant() / det,
								-Matrix_2x2(_11, _12, _31, _32).Determinant() / det,
								Matrix_2x2(_12, _13, _22, _23).Determinant() / det,
								-Matrix_2x2(_11, _13, _21, _23).Determinant() / det,
								Matrix_2x2(_11, _12, _21, _22).Determinant() / det);
		}
	}
}