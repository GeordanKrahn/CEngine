//This class is the implmentation of include/matrix4.h
//     ┌                          ┐
//     | M11    M12    M13    M14 |
//     | M21    M22    M23    M24 |
//     | M31    M32    M33    M34 |
//     | M41    M42    M43    M44 |
//     └                          ┘
#pragma once
#include "../include/functions.h"
#include "../include/matrix4.h"
#include "../include/matrix3.h"
namespace Engine
{
	namespace Mathematics
	{
		Matrix_4x4::Matrix_4x4()
		{
			_11 = 0; _12 = 0; _13 = 0;
			_21 = 0; _22 = 0; _23 = 0;
			_31 = 0; _32 = 0; _33 = 0;
		}

		Matrix_4x4::Matrix_4x4(	const double& m11, const double& m12, const double& m13, const double& m14,
								const double& m21, const double& m22, const double& m23, const double& m24,
								const double& m31, const double& m32, const double& m33, const double& m34, 
								const double& m41, const double& m42, const double& m43, const double& m44)
		{
			_11 = m11; _12 = m12; _13 = m13; _14 = m14;
			_21 = m21; _22 = m22; _23 = m23; _24 = m24;
			_31 = m31; _32 = m32; _33 = m33; _34 = m34;
			_41 = m41; _42 = m42; _43 = m43; _44 = m44;
		}

		Matrix_4x4::Matrix_4x4(const double arr[4][4])
		{
			_11 = arr[0][0]; _12 = arr[0][1]; _13 = arr[0][2]; _14 = arr[0][3];
			_21 = arr[1][0]; _22 = arr[1][1]; _23 = arr[1][2]; _24 = arr[1][3];
			_31 = arr[2][0]; _32 = arr[2][1]; _33 = arr[2][2]; _34 = arr[2][3];
			_41 = arr[3][0]; _42 = arr[3][1]; _43 = arr[3][2]; _44 = arr[3][3];
		}

		Matrix_4x4::Matrix_4x4(const Vector4 arr[4])
		{
			_11 = arr[0].x; _12 = arr[1].x; _13 = arr[2].x; _14 = arr[3].x;
			_21 = arr[0].y; _22 = arr[1].y; _23 = arr[2].y; _24 = arr[3].y;
			_31 = arr[0].z; _32 = arr[1].z; _33 = arr[2].z; _34 = arr[3].z;
			_41 = arr[0].w; _42 = arr[1].w; _43 = arr[2].w; _44 = arr[3].w;
		}

		Matrix_4x4::Matrix_4x4(const Vector4& a, const Vector4& b, const Vector4& c, const Vector4& d)
		{
			_11 = a.x; _12 = b.x; _13 = c.x; _14 = d.x;
			_21 = a.y; _22 = b.y; _23 = c.y; _24 = d.y;
			_31 = a.z; _32 = b.z; _33 = c.z; _34 = d.z;
			_41 = a.w; _42 = b.w; _43 = c.w; _44 = d.w;
		}

		Matrix_4x4::Matrix_4x4(const Matrix_4x4& m)
		{
			_11 = m.m11; _12 = m.m12; _13 = m.m13; _14 = m.m14;
			_21 = m.m21; _22 = m.m22; _23 = m.m23; _24 = m.m24;
			_31 = m.m31; _32 = m.m32; _33 = m.m33; _34 = m.m34;
			_41 = m.m41; _42 = m.m42; _43 = m.m43; _44 = m.m44;
		}

		Matrix_4x4 Matrix_4x4::CreateRollRotationMatrix(const double& degrees)
		{
			return Matrix_4x4(	cos(Functions::DegreesToRadians(degrees)),	-sin(Functions::DegreesToRadians(degrees)),	0, 0,
								sin(Functions::DegreesToRadians(degrees)),	cos(Functions::DegreesToRadians(degrees)),	0, 0, 
								0,											0,											1, 0, 
								0,											0,											0, 1);
		}

		Matrix_4x4 Matrix_4x4::CreatePitchRotationMatrix(const double& degrees)
		{
			return Matrix_4x4(	1, 0,											0,											0,
								0, cos(Functions::DegreesToRadians(degrees)),	-sin(Functions::DegreesToRadians(degrees)),	0,
								0, sin(Functions::DegreesToRadians(degrees)),	cos(Functions::DegreesToRadians(degrees)),	0,
								0, 0,											0,											1);
		}

		Matrix_4x4 Matrix_4x4::CreateYawRotationMatrix(const double& degrees)
		{
			return Matrix_4x4(	cos(Functions::DegreesToRadians(degrees)),	0,	sin(Functions::DegreesToRadians(degrees)),	0,
								0,											1,	0,											0,
								-sin(Functions::DegreesToRadians(degrees)), 0,	cos(Functions::DegreesToRadians(degrees)),	0,
								0,											0,	0,											1);
		}
		Matrix_4x4 Matrix_4x4::Create3DTransformationMatrix(const double& shiftX, const double& shiftY, const double& shiftZ, const double& scaleX, const double& scaleY, const double& scaleZ)
		{
			return Matrix_4x4(	scaleX,	0,		0,		shiftX,
								0,		scaleY, 0,		shiftY,
								0,		0,		scaleZ, shiftZ,
								0,		0,		0,		1);
		}

		void Matrix_4x4::Identity()
		{
			_11 = 1; _12 = 0; _13 = 0; _14 = 0;
			_21 = 0; _22 = 1; _23 = 0; _24 = 0;
			_31 = 0; _32 = 0; _33 = 1; _34 = 0;
			_41 = 0; _42 = 0; _43 = 0; _44 = 1;
		}

		void Matrix_4x4::SetElement(const int& row, const int& col, const double& val)
		{
			if (!(row > 4 || row < 1 || col > 4 || col < 1)) { m[row - 1][col - 1] = val; }
		}
		double Matrix_4x4::Determinant() const
		{
			return (_11 * Matrix_3x3(_22, _23, _24, _32, _33, _34, _42, _43, _44).Determinant() -
					_12 * Matrix_3x3(_21, _23, _24, _31, _33, _34, _41, _43, _44).Determinant() +
					_13 * Matrix_3x3(_21, _22, _24, _31, _32, _34, _41, _42, _44).Determinant() -
					_14 * Matrix_3x3(_21, _22, _23, _31, _32, _33, _41, _42, _43).Determinant());
		}
		double Matrix_4x4::Determinant(const Matrix_4x4& m) { return m.Determinant(); }
		Matrix_4x4 Matrix_4x4::Inverse() const
		{
			double det = Determinant();
			return Matrix_4x4(Matrix_2x2(_22, _23, _32, _33).Determinant() / det,
				-Matrix_2x2(_21, _23, _31, _33).Determinant() / det,
				Matrix_2x2(_21, _22, _31, _32).Determinant() / det,
				-Matrix_2x2(_12, _13, _32, _33).Determinant() / det,
				Matrix_2x2(_11, _13, _31, _33).Determinant() / det,
				-Matrix_2x2(_11, _12, _31, _32).Determinant() / det,
				Matrix_2x2(_12, _13, _22, _23).Determinant() / det,
				-Matrix_2x2(_11, _13, _21, _23).Determinant() / det,
				Matrix_2x2(_11, _12, _21, _22).Determinant() / det).Transpose();
		}
	}
}