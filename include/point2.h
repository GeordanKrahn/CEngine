#pragma once
#include <iostream>
#include <ostream>
#include <memory>

//This is a Point in 2D space
namespace Engine 
{
    namespace Mathematics
    {
        class Point2D
        {
        private:
        // properties
            std::unique_ptr<double> _x;
            std::unique_ptr<double> _y;
        public:
        // Setter & Getters
            const double& x = *_x;
            const double& y = *_y;
            void SetX(double x) { *_x = x; }
            void SetY(double y) { *_y = y; }
        
        // Constructors
            Point2D() : _x(new double(0)), _y(new double(0)) {}
            Point2D(const double& X, const double& Y) : _x(new double(X)), _y(new double(Y)) {}
            Point2D(const Point2D & p) : _x(new double(p.x)), _y(new double(p.y)) {}
        // copy constructor and assignment overload.
            Point2D operator =(const Point2D& p) { return Point2D(p); }
        // class methods
            double SegmentLength(const Point2D & p) const;
            Point2D MidPoint(const Point2D & p) const;
        // Operator Overloads
            Point2D operator *(const double& s) { return Point2D(x * s, y * s); }
        };

        // Operator Overloads
        // non member operator overloads
        Point2D operator *(const double& a, const Point2D& b);
        bool operator ==(const Point2D& a, const Point2D& b);
        bool operator !=(const Point2D& a, const Point2D& b);
        // Left shift operator for cout compatibility
        std::ostream& operator <<(std::ostream& cout, const Point2D & p);
    }
}