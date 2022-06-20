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
            double _X;
            double _Y;
        public:
        // Setter & Getters
            const double & X = _X;
            const double & Y = _Y;
            void SetX(double X);
            void SetY(double Y);
        
        // Constructors
            Point2D() : _X(0), _Y(0) {}
            Point2D(double X, double Y) : _X(X), _Y(Y) {}
            Point2D(const Point2D & b) : _X(b.X), _Y(b.Y) {}
        // copy constructor and assignment overload.
            Point2D & operator = (Point2D & rh)
            {
                Point2D *ref = new Point2D();
                if (this != nullptr)
                {
                    ref = this;
                }
                else
                {
                    delete ref;
                    ref = nullptr;
                }
                return *ref;
            }
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
        std::ostream& operator <<(std::ostream& cout, const Point2D& a);
    }
}