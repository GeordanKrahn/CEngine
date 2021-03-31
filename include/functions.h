//This is a generic class to hold miscellaneous math functions required for the engine
#include <tuple>

//Angle conversions degrees <--> radians
double toRadians(double degrees);
double toDegrees(double radians);

//Quadratic equation solvers
double quadraticNegative(double a, double b, double c);
double quadraticPositive(double a, double b, double c);

//Trigonometry solvers
std::tuple<double, double> calculateAdjacentOpposite(double degrees, double hypotenuse);
std::tuple<double, double> calculateAdjacentHypotenuse(double degrees, double opposite);
std::tuple<double, double> calculateOppositeHypotenuse(double degrees, double adjacent);
std::tuple<double, double> calculateHypotenuseTheta(double adjacent, double opposite);
std::tuple<double, double> calculateAdjacentTheta(double opposite, double hypotenuse);
std::tuple<double, double> calculateOppositeTheta(double adjacent, double hypotenuse);
