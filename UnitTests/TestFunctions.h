#pragma once
#include "Test.h"
#include <cmath>
using namespace Engine::Mathematics;

namespace Testing
{
	auto roundTo8th = [=](const double& val)->long { return (long)round(100000000 * val); };
	TEST(TestFunctions, TestDegreesToRadians)
	{
		double radians = 1.570796327;
		double degrees = 90;
		double actual = Functions::DegreesToRadians(degrees);
		EXPECT_EQ(roundTo8th(actual), roundTo8th(radians));
	}
}
