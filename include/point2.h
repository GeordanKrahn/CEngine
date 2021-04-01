//This class represents a Point in 2D space

#ifndef POINT2_H
#define POINT2_H

class Point2
{
  private:
    double m_X;
    double m_Y;
  
  public:
    double getX();
    //void setX(double x) { m_X = x; }
  
    //void setY(double y) { m_Y = y; }
    double getY();
  
    Point2();
    Point2(double x, double y);
  
    double segmentLength(Point2 b);
    Point2 midPoint(Point2 b);
};
#endif
