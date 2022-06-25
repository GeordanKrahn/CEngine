#pragma once
#include "Test.h"
#include <memory>
using namespace Engine::Mathematics;

namespace Testing
{
	TEST(TestFunctions, TestDegreesToRadians)
	{
		double radians = 1.570796327;
		double degrees = 90;
		double actual = Functions::DegreesToRadians(degrees);
		EXPECT_EQ(actual, radians);
	}

	TEST(TestFunctions, TestRadiansToDegrees)
	{
		double radians = 1.550796327;
		double degrees = 90;
		double actual = Functions::RadiansToDegrees(radians);
		EXPECT_NE(actual, degrees);
	}

	// The next 6 tests fail due to precision errors
	TEST(TestFunctions, TestRightTriangleGivenAngleAndHypotinuse)
	{
		double deg = 35.0, hyp = 10.0;
		double expAdj = 8.191520443;
		double expOpp = 5.735764364;
		auto expected = tuple<double, double>(expAdj, expOpp);
		auto actual = Functions::RightTriangleGivenAngleAndHypotinuse(deg, hyp);
		EXPECT_EQ(roundTo(std::get<0>(actual), 8), roundTo(std::get<0>(expected), 8));
		EXPECT_EQ(roundTo(std::get<1>(actual), 8), roundTo(std::get<1>(expected), 8));
	}

	TEST(TestFunctions, TestRightTriangleGivenAngleAndOpposite)
	{
		double deg = 35.0, opp = 5.735764364;
		double expAdj = 8.191520443;
		double expHyp = 10.0;
		auto expected = tuple<double, double>(expAdj, expHyp);
		auto actual = Functions::RightTriangleGivenAngleAndOpposite(deg, opp);
		EXPECT_EQ(roundTo(std::get<0>(actual), 8), roundTo(std::get<0>(expected), 8));
		EXPECT_EQ(roundTo(std::get<1>(actual), 8), roundTo(std::get<1>(expected), 8));
	}

	TEST(TestFunctions, TestRightTriangleGivenAngleAndAdjacent)
	{
		double deg = 35.0, adj = 8.191520443;
		double expOpp = 5.735764364;
		double expHyp = 10.0;
		auto expected = tuple<double, double>(expOpp, expHyp);
		auto actual = Functions::RightTriangleGivenAngleAndAdjacent(deg, adj);
		EXPECT_EQ(roundTo(std::get<0>(actual), 8), roundTo(std::get<0>(expected), 8));
		EXPECT_EQ(roundTo(std::get<1>(actual), 8), roundTo(std::get<1>(expected), 8));
	}

	TEST(TestFunctions, TestRightTriangleGivenOppositeAndAdjacent)
	{
		double opp = 5.735764364, adj = 8.191520443;
		double expHyp = 10.0;
		double expDeg = 35.0;
		auto expected = tuple<double, double>(expHyp, expDeg);
		auto actual = Functions::RightTriangleGivenOppositeAndAdjacent(opp, adj);
		EXPECT_EQ(roundTo(std::get<0>(actual), 8), roundTo(std::get<0>(expected), 8));
		EXPECT_EQ(roundTo(std::get<1>(actual), 8), roundTo(std::get<1>(expected), 8));
	}

	TEST(TestFunctions, TestRightTriangleGivenOppositeAndHypotinuse)
	{
		double opp = 5.735764364, hyp = 10.0;
		double expAdj = 8.191520443;
		double expDeg = 35.0;
		auto expected = tuple<double, double>(expAdj, expDeg);
		auto actual = Functions::RightTriangleGivenOppositeAndHypotinuse(opp, hyp);
		EXPECT_EQ(roundTo(std::get<0>(actual), 8), roundTo(std::get<0>(expected), 8));
		EXPECT_EQ(roundTo(std::get<1>(actual), 8), roundTo(std::get<1>(expected), 8));
	}

	TEST(TestFunctions, TestRightTriangleGivenAdjacentAndHypotinuse)
	{
		double adj = 8.191520443, hyp = 10.0;
		double expOpp = 5.735764364;
		double expDeg = 35.0;
		auto expected = tuple<double, double>(expOpp, expDeg);
		auto actual = Functions::RightTriangleGivenAdjacentAndHypotinuse(adj, hyp);
		EXPECT_EQ(roundTo(std::get<0>(actual), 8), roundTo(std::get<0>(expected), 8));
		EXPECT_EQ(roundTo(std::get<1>(actual), 8), roundTo(std::get<1>(expected), 8));
	}

	TEST(TestFunctions, TestRightQuadraticPositive)
	{
		double a = 1.0, b = -1.0, c = -6.0;
		double expected = 3.0;
		double actual = Functions::QuadraticPositive(a, b, c);
		EXPECT_EQ(actual, expected);
	}

	TEST(TestFunctions, TestRightQuadraticNegative)
	{
		double a = 1.0, b = -1.0, c = -6.0;
		double expected = 3.0;
		double actual = Functions::QuadraticPositive(a, b, c);
		EXPECT_EQ(actual, expected);
	}
}
