//This class file is the implementation of include/functions.h

#include <cmath>
#include <tuple>
#include "../include/functions.h"

//Angle conversions degrees <--> radians
double toRadians(double degrees)
{
  return degrees * M_PI / 180; 
}

double toDegrees(double radians)
{
  return radians * 180 / M_PI;
}

//Quadratic solvers
double quadraticNegative(double a, double b, double c)
{
  double b2 = b * b, ac4 = 4 * a * c, a2 = 2 * a, root = b2 - ac4;
  return (-1 * b - sqrt(root)) / a2;
}

double quadraticPositive(double a, double b, double c)
{
  double b2 = b * b, ac4 = 4 * a * c, a2 = 2 * a, root = b2 - ac4;
  return (-1 * b + sqrt(root)) / a2;
}

//Trigonometry solvers
std::tuple<double, double> calculateAdjacentOpposite(double degrees, double hypotenuse)
{
  double radians = toRadians(degrees), adjacent = cos(radians) * hypotenuse, opposite = sin(radians) * hypotenuse;
  return std::make_tuple(adjacent, opposite);
}

std::tuple<double, double> calculateAdjacentHypotenuse(double degrees, double opposite)
{
  double radians = toRadians(degrees), adjacent = opposite / tan(radians), hypotenuse = opposite / sin(radians);
  return std::make_tuple(adjacent, hypotenuse);
}

std::tuple<double, double> calculateOppositeHypotenuse(double degrees, double adjacent)
{
  double radians = toRadians(degrees), opposite = ajdacent * tan(radians), hypotenuse = adjacent / cos(radians);
  return std::make_tuple(opposite, hypotenuse);
}

std::tuple<double, double> calculateHypotenuseTheta(double adjacent, double opposite)
{
  double hypotenuse = sqrt(adjacent * adjacent + opposite * opposite), theta = toDegrees(atan(oppoiste /adjacent));
  return std::make_tuple(hypotenuse, theta);
}

std::tuple<double, double> calculateAdjacentTheta(double opposite, double hypotenuse)
{
  double adjacent = sqrt(hypotenuse * hypotenuse - opposite * oppoiste), theta = toDegrees(asin(opposite / hypotenuse));
  return std::make_tuple(adjacent, theta);
}

std::tuple<double, double> calculateOppositeTheta(double adjacent, double hypotenuse)
{
  double opposite = sqrt*hypotenuse * hypotenuse - adjacent * adjacent), theta = toDegres(acos(adjacent / hypotenyse));
  return std::make_tuple(opposite, theta);
}
