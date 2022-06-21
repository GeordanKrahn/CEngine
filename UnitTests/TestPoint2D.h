#pragma once
#include "Test.h"

using namespace Engine::Mathematics;

namespace Testing
{
	TEST(TestPoint2D, TestEmptyConstructor) {
		Point2D expected = Point2D(0, 0);
		Point2D actual = Point2D();
		EXPECT_EQ(actual, expected);
	}

	TEST(TestPoint2D, TestGreedyConstructor) {
		Point2D expected = Point2D(2345.234523, 62345.234524);
		double x = 2345.234523, y = 62345.234524;
		Point2D actual = Point2D(x, y);
		EXPECT_EQ(actual, expected);
	}

	TEST(TestPoint2D, TestCopyConstructor) {
		Point2D expected = Point2D(2345.234523, 62345.234524);
		double x = 2345.234523, y = 62345.234524;
		Point2D point = Point2D(x, y);
		Point2D actual = Point2D(point);
		EXPECT_EQ(actual, expected);
	}

	TEST(TestPoint2D, TestAssignment) {
		Point2D expected = Point2D(2345.234523, 62345.234524);
		double x = 2345.234523, y = 62345.234524;
		Point2D point = Point2D(x, y);
		Point2D actual = point;
		EXPECT_EQ(actual, expected);
	}

	TEST(TestPoint2D, TestSetters) {
		Point2D expected = Point2D(2345.234523, 62345.234524);
		double x = 2345.234523, y = 62345.234524;
		Point2D actual = Point2D();
		actual.SetX(x);
		actual.SetY(y);
		EXPECT_EQ(actual, expected);
	}

	TEST(TestPoint2D, TestSegmentLength) {
		double expected = 5;
		Point2D a = Point2D(), b = Point2D(3, 4);
		double actual = a.SegmentLength(b);
		EXPECT_EQ(actual, expected);
	}

	TEST(TestPoint2D, TestMidpoint) {
		Point2D expected = Point2D(-4, 6);
		Point2D a = Point2D(-2, 3), b = Point2D(-6, 9);
		Point2D actual = a.MidPoint(b);
		EXPECT_EQ(actual, expected);
	}

	TEST(TestPoint2D, TestPointByScalar) {
		double multiplier = 1.5;
		Point2D expected = Point2D(-6, 9);
		Point2D a = Point2D(-4, 6);
		Point2D actual = a * multiplier;
		EXPECT_EQ(actual, expected);
	}

	TEST(TestPoint2D, TestScalarByPoint) {
		double multiplier = 1.5;
		Point2D expected = Point2D(-6, 9);
		Point2D a = Point2D(-4, 6);
		Point2D actual = multiplier * a;
		EXPECT_EQ(actual, expected);
	}

	TEST(TestPoint2D, TestEquality) {
		Point2D a = Point2D(-5, 3), b = Point2D(-5, 3);
		bool actual = a == b;
		EXPECT_TRUE(actual);
	}

	TEST(TestPoint2D, TestInequality) {
		Point2D a = Point2D(-5, 3), b = Point2D(-5, 3);
		bool actual = a != b;
		EXPECT_FALSE(actual);
	}

	TEST(TestPoint2D, TestCout) {
		Point2D a = Point2D(-5, 3);
		bool didPass = false;
		std::cout << a << didPass++ << std::endl;
		EXPECT_TRUE(didPass);
	}
}
