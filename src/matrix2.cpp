//This class is the implementation of incldue/matrix2.h
//     ┌            ┐
//     | M11    M12 |
//     | M21    M22 |
//     └            ┘
#pragma once
#include "../include/matrix2.h"
namespace Engine
{
	namespace Mathematics
	{
		Matrix_2x2::Matrix_2x2()
		{
			_11 = 0;
			_12 = 0;
			_21 = 0;
			_22 = 0;
		}

		Matrix_2x2::Matrix_2x2(const double& m11, const double& m12, const double& m21, const double& m22)
		{
			_11 = m11;
			_12 = m12;
			_21 = m21;
			_22 = m22;
		}

		Matrix_2x2::Matrix_2x2(const double arr[2][2])
		{
			_11 = arr[0][0];
			_12 = arr[0][1];
			_21 = arr[1][0];
			_22 = arr[1][1];
		}

		Matrix_2x2::Matrix_2x2(const Vector2 arr[2])
		{
			_11 = arr[0].x;
			_12 = arr[1].x;
			_21 = arr[0].y;
			_22 = arr[1].y;
		}

		Matrix_2x2::Matrix_2x2(const Vector2& a, const Vector2& b)
		{
			_11 = a.x;
			_12 = b.x;
			_21 = a.y;
			_22 = b.y;
		}

		Matrix_2x2::Matrix_2x2(const Matrix_2x2& m)
		{
			_11 = m.m11;
			_12 = m.m12;
			_21 = m.m21;
			_22 = m.m22;
		}

		Matrix_2x2 Matrix_2x2::operator =(const Matrix_2x2& m) const{ return Matrix_2x2(m); }
		void Matrix_2x2::SetElement(const int& row, const int& col, const double& val)
		{
			if(!(row > 2 || row < 1 || col > 2 || col < 1))	{ m[row - 1][col - 1] = val; }
		}
		double Matrix_2x2::Determinant() const { return m[0][0] * m[1][1] - m[0][1] * m[1][0]; }
		double Matrix_2x2::Determinant(const Matrix_2x2& m) { return m.Determinant(); }
	}
}