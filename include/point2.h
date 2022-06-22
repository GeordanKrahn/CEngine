#pragma once
#include <iostream>
#include <ostream>

//This is a Point in 2D space
namespace Engine 
{
    namespace Mathematics
    {
        class Point2D
        {
        private:
        // properties
            double* _X;
            double* _Y;
        public:
        // Setter & Getters
            const double& X = *_X;
            const double& Y = *_Y;
            void SetX(double X) { *_X = X; }
            void SetY(double Y) { *_Y = Y; }
        
        // Constructors
            Point2D() : _X(new double(0)), _Y(new double(0)) {}
            Point2D(const double& X, const double& Y) : _X(new double(X)), _Y(new double(Y)) {}
            Point2D(const Point2D & b) : _X(new double(b.X)), _Y(new double(b.Y)) {}
        // Destructor
            ~Point2D();
        // copy constructor and assignment overload.
            Point2D operator =(const Point2D& rh) { return Point2D(rh); }
        // class methods
            double SegmentLength(const Point2D & b) const;
            Point2D MidPoint(const Point2D & b) const;
        // Operator Overloads
            Point2D operator *(const double& rh);
        };

        // Operator Overloads
        // non member operator overloads
        Point2D operator *(const double& lh, const Point2D& rh);
        bool operator ==(const Point2D& a, const Point2D& b);
        bool operator !=(const Point2D& a, const Point2D& b);
        // Left shift operator for cout compatibility
        std::ostream& operator <<(std::ostream& cout, const Point2D & a);
    }
}