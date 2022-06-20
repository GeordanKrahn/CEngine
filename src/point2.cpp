//This class is the implementation of include.point2.h
#pragma once
#include "point2.h"
#include <math.h>
namespace Engine
{
    namespace Mathematics
    {
        // setters
        void Point2D::SetX(double X) { _X = X; }
        void Point2D::SetY(double Y) { _Y = Y; }
        // class methods
        double Point2D::SegmentLength(const Point2D & b) const
        {
            return sqrt( pow(b.X - X, 2) + pow(b.Y - Y, 2));
        }
        Point2D Point2D::MidPoint(const Point2D & b) const
        {
            return Point2D(0.5 * (b.X + X), 0.5 * (b.Y + Y));
        }

        // operator overloads
        Point2D Point2D::operator *(const double& rh)
        {
            return Point2D(X * rh, Y * rh);
        }

        // non member operator overloads
        Point2D operator *(const double & lh, const Point2D & rh)
        {
            return Point2D(lh * rh.X, lh * rh.Y);
        }
        bool operator ==(const Point2D & a, const Point2D & b)
        {
            return (a.X == b.X && a.Y == b.Y);
        }
        bool operator !=(const Point2D & a, const Point2D & b)
        {
            return !(a==b);
        }
        // Left shift operator for cout compatibility
        std::ostream& operator <<(std::ostream& cout, const Point2D& a)
        {
            cout << "P(" << a.X << ", " << a.Y << ")";
            return cout;
        }
    }
}
