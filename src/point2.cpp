//This class is the implementation of include.point2.h
#pragma once
#include "../include/point2.h"

namespace Engine
{
    namespace Mathematics
    {
        // class methods
        double Point2D::SegmentLength(const Point2D & p) const
        {
            return sqrt( pow(p.x - x, 2) + pow(p.y - y, 2));
        }
        Point2D Point2D::MidPoint(const Point2D & p) const
        {
            return Point2D(0.5 * (p.x + x), 0.5 * (p.y + y));
        }

        // non member operator overloads
        Point2D operator *(const double & a, const Point2D & b)
        {
            return Point2D(a * b.x, a * b.y);
        }
        bool operator ==(const Point2D& a, const Point2D& b)
        {
            return a.x == b.x && a.y == b.y;
        }

        bool operator !=(const Point2D& a, const Point2D& b)
        {
            return a.x != b.x || a.y != b.y;
        }

        // Left shift operator for cout compatibility
        std::ostream& operator <<(std::ostream& cout, const Point2D & p)
        {
            cout << "P(" << p.x << ", " << p.y << ")";
            return cout;
        }
    }
}
