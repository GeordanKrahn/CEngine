//This is a generic class to hold miscellaneous math functions required for the engine
#pragma once
#include <iostream>
#include <ostream>
#include <math.h>
#include <tuple>

#define tuple std::tuple

namespace Engine
{
    namespace Mathematics
    {
        class Functions
        {
        private:
            constexpr static double pi = 3.141592654;
        public:
            static double DegreesToRadians(const double& deg);
            static double RadiansToDegrees(const double& rad);
            static tuple<double, double> RightTriangleGivenAngleAndHypotinuse(const double& deg, const double& hyp);
            static tuple<double, double> RightTriangleGivenAngleAndOpposite(const double& deg, const double& opp);
            static tuple<double, double> RightTriangleGivenAngleAndAdjacent(const double& deg, const double& adj);
            static tuple<double, double> RightTriangleGivenOppositeAndAdjacent(const double& opp, const double& adj);
            static tuple<double, double> RightTriangleGivenOppositeAndHypotinuse(const double& opp, const double& hyp);
            static tuple<double, double> RightTriangleGivenAdjacentAndHypotinuse(const double& adj, const double& hyp);
            static double QuadraticNegative(const double& a, const double& b, const double& c);
            static double QuadraticPositive(const double& a, const double& b, const double& c);
        };
    }
}