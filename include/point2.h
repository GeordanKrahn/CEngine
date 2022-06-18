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
        // copy constructor and assignment overload.
            Point2D & operator = (const Point2D & rh){ return Point2D(rh.X, rh.Y); }
        // class methods
            double SegmentLength(const Point2D & b) const;
            Point2D * MidPoint(const Point2D & b) const;

        // Operator Overloads
            // non member functions
        };
    }
}