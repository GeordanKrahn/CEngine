#pragma once
#include "Test.h"
using namespace Engine::Mathematics;

namespace Testing
{
	TEST(TestFunctions, TestDegreesToRadians)
	{
		double radians = 1.570796327;
		double degrees = 90;
		double actual = Functions::DegreesToRadians(degrees);
		EXPECT_EQ(roundTo8th(actual), roundTo8th(radians));
	}
}
