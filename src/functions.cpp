//This class file is the implementation of include/functions.h
#include "../include/functions.h"

namespace Engine
{
	namespace Mathematics
	{
		double Functions::DegreesToRadians(const double& deg) { return (pi / 180.0) * deg; }
		double Functions::RadiansToDegrees(const double& rad) { return (180.0 / pi) * rad; }
		
		/// <summary>
		/// solves a right triangle
		/// </summary>
		/// <param name="deg"></param>
		/// <param name="hyp"></param>
		/// <returns>item1(adj) item2(opp)</returns>
		tuple<double, double> Functions::RightTriangleGivenAngleAndHypotinuse(const double& deg, const double& hyp)
		{
			double opp = hyp * sin(DegreesToRadians(deg));
			double adj = hyp * cos(DegreesToRadians(deg));
			return tuple<double, double>(adj, opp);
		}

		/// <summary>
		/// solves a right triangle
		/// </summary>
		/// <param name="deg"></param>
		/// <param name="opp"></param>
		/// <returns>item1(adj) item2(hyp)</returns>
		tuple<double, double> Functions::RightTriangleGivenAngleAndOpposite(const double& deg, const double& opp)
		{
			double adj = opp / tan(DegreesToRadians(deg));
			double hyp = sqrt(pow(opp, 2) + pow(adj, 2));
			return tuple<double, double>(adj, hyp);
		}

		/// <summary>
		/// solves a right triangle
		/// </summary>
		/// <param name="deg"></param>
		/// <param name="adj"></param>
		/// <returns>item1(opp) item2(hyp)</returns>
		tuple<double, double> Functions::RightTriangleGivenAngleAndAdjacent(const double& deg, const double& adj) 
		{
			double opp = adj * tan(DegreesToRadians(deg));
			double hyp = sqrt(pow(opp, 2) + pow(adj, 2));
			return tuple<double, double>(opp, hyp);
		}

		/// <summary>
		/// solves a right triangle
		/// </summary>
		/// <param name="opp"></param>
		/// <param name="adj"></param>
		/// <returns>item1(hyp) item2(deg)</returns>
		tuple<double, double> Functions::RightTriangleGivenOppositeAndAdjacent(const double& opp, const double& adj)
		{
			double hyp = sqrt(pow(opp, 2) + pow(adj, 2));
			double rad = atan2(opp, adj);
			double deg = RadiansToDegrees(rad);
			return tuple<double, double>(hyp, deg);
		}

		/// <summary>
		/// solves a right triangle
		/// </summary>
		/// <param name="opp"></param>
		/// <param name="hyp"></param>
		/// <returns>item1(adj) item2(deg)</returns>
		tuple<double, double> Functions::RightTriangleGivenOppositeAndHypotinuse(const double& opp, const double& hyp)
		{
			double adj = sqrt(pow(hyp, 2) - pow(opp, 2));
			double rad = atan2(opp, adj);
			double deg = RadiansToDegrees(rad);
			return tuple<double, double>(adj, deg);
		}

		/// <summary>
		/// solves a right triangle
		/// </summary>
		/// <param name="adj"></param>
		/// <param name="hyp"></param>
		/// <returns>item1(opp) item2(deg)</returns>
		tuple<double, double> Functions::RightTriangleGivenAdjacentAndHypotinuse(const double& adj, const double& hyp)
		{
			double opp = sqrt(pow(hyp, 2) - pow(adj, 2));
			double rad = atan2(opp, adj);
			double deg = RadiansToDegrees(rad);
			return tuple<double, double>(opp, deg);
		}

		double Functions::QuadraticNegative(const double& a, const double& b, const double& c)
		{
			return (-1.0 * b - sqrt((b * b) - (4.0 * a * c))) / (2.0 * a);
		}

		double Functions::QuadraticPositive(const double& a, const double& b, const double& c)
		{
			return (-1.0 * b + sqrt((b * b) - (4.0 * a * c))) / (2.0 * a);
		}
	}
}