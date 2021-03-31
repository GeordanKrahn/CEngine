//This class is the implementation of include/point2.h
#include<cmath>

class Point2
{
  private:
    double m_X;
    double m_Y;
  
  public:
    double getX() { return m_X; }
    void setX(double x) { m_X = x; }
  
    void setY(double y) { m_Y = y; }
    double getY() { return m_Y; }
  
    Point2()
    {
      m_X = 0;
      m_Y = 0;
    }
  
    Point2(double x, double y)
    {
      m_X = setX(x);
      m_Y = setY(y);
    }
  
    double segmentLength(Point2 b)
    {
      return sqrt(pow(b.getX() - this.getX(), 2) + pow(b.getY() - this.getY(), 2));
    }
  
    Point2 midPoint(Point2 b)
    {
      return Point2(0.5 * (getX() + b.getX()), 0.5 * (getY() + b.getY());
    }
};
