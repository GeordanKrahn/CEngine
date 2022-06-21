#pragma once
#include "pch.h"

#include "../include/body.h"
#include "../include/functions.h"
#include "../include/matrix2.h"
#include "../include/matrix3.h"
#include "../include/matrix4.h"
#include "../include/point2.h"
#include "../include/quaternion.h"
#include "../include/vector2.h"
#include "../include/vector3.h"

// including the .cpp files gets rid of lnk2019 error
#include "../src/body.cpp"
#include "../src/functions.cpp"
#include "../src/matrix2.cpp"
#include "../src/matrix3.cpp"
#include "../src/matrix4.cpp"
#include "../src/point2.cpp"
#include "../src/quaternion.cpp"
#include "../src/vector2.cpp"
#include "../src/vector3.cpp"

#include "gtest/gtest.h"

namespace Testing
{
	auto roundTo8th = [=](const double& val)->long { return (long)round(100000000 * val); };
}