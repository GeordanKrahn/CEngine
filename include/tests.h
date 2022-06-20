#pragma once
#include <iostream>
#include <chrono>
#include "point2.h"

// This is where all tests will be performed. They will be run from tests.cpp in the main() method.

using namespace Engine::Mathematics;
using namespace std;

// Consider creating a test class
struct Count
{
    int tests = 0;
    int pass = 0;
};
Count TestCounts;
class Assert
{
public:
    template<typename T>
    static void AreEqual(T expected, T actual, const char* testName)
    {
        cout.precision(10);
        auto timerStart = chrono::steady_clock::now();
        bool isRunning = false, isEqual = expected == actual;
        auto msg = [&]()->void { cout << "Test " << (!isRunning ? TestCounts.tests : ++TestCounts.tests) << ": " << (isRunning ? "Running " : "Finished ") << testName << endl; };
        auto output = [&]()->void
        {
            cout << "Status: " << (isEqual ? "Passed" : "Failed") << endl;
            if (!isEqual) { cout << "Expected: " << expected << "\n" << "Actual: " << actual << endl; }
            TestCounts.pass = isEqual ? ++TestCounts.pass : TestCounts.pass;
        };
        isRunning = true;
        msg();
        output();
        isRunning = false;
        auto timerEnd = chrono::steady_clock::now();
        auto difference = (timerEnd - timerStart).count();
        cout << "Test completed in: " << difference << " ns\n" << endl;
    };
};

// Run Point2D Tests
// Point2D()
void TestEmptyConstructor()
{
    Point2D actual = Point2D();
    Point2D expected = Point2D(0, 0);
    Assert::AreEqual(expected, actual, "Test Empty Constructor");
}

// Point2D(double X, double Y)
void TestGreedyConstructor()
{
    Point2D expected = Point2D(3.1415,7.777777);
    double x = 3.1415, y = 7.777777;
    Point2D actual = Point2D(x, y);
    Assert::AreEqual(expected, actual, "Test Greedy Constructor");
}

// Point2D(const Point2D& b)
void TestCopyConstructor()
{
    Point2D expected = Point2D(15.24, 67.43333);
    Point2D point = Point2D(15.24, 67.43333);
    Point2D actual = Point2D(point);
    Assert::AreEqual(expected, actual, "Test Copy Constructor");
}

// Point2D & operator = (Point2D & rh)
void TestAssignmentCopyConstructor()
{
    Point2D expected = Point2D(15.24, 67.43333);
    Point2D point = Point2D(15.24, 67.43333);
    Point2D actual = point;
    Assert::AreEqual(expected, actual, "Test Copy Assignment Constructor");
}

// void SetX(double X);
// void SetY(double Y);
void TestSetters()
{
    double x = 12.4334, y = 53.333445;
    Point2D expected = Point2D(12.4334, 53.333444);
    Point2D actual = Point2D();
    actual.SetX(x);
    actual.SetY(y);
    Assert::AreEqual(expected, actual, "Test Setters");
}

// double SegmentLength(const Point2D & b) const;
void TestSegmentLength()
{
    double expected = 5;
    Point2D a = Point2D(0, 0), b = Point2D(3, 4);
    double actual = a.SegmentLength(b);
    Assert::AreEqual(expected, actual, "Test Segment Length");
}

// Point2D MidPoint(const Point2D & b) const;
void TestMidPoint()
{
    Point2D a = Point2D(0, 0), b = Point2D(-3, 4), expected = Point2D(-1.5, 2);
    Point2D actual = a.MidPoint(b);
    Assert::AreEqual(expected, actual, "Test Mid Point");
}

// bool operator ==(const Point2D& a, const Point2D& b);
void TestEquality()
{
    Point2D a = Point2D(4, 2.222), b = Point2D(4, 2.222);
    bool expected = true;
    bool actual = a == b;
    Assert::AreEqual(expected, actual, "Test Equality");
}

// bool operator !=(const Point2D & a, const Point2D & b)
void TestInequality()
{
    Point2D a = Point2D(4, 2.222), b = Point2D(4, 2.222);
    bool expected = false;
    bool actual = a != b;
    Assert::AreEqual(expected, actual, "Test Inequality");
}

// Point2D operator *(const double& lh, const Point2D& rh);
void TestScalarMultiplication_NonMember()
{
    double multiple = 1.5;
    Point2D expected = Point2D(6, -9), point = Point2D(4, -6);
    Point2D actual = multiple * point;
    Assert::AreEqual(expected, actual, "Test Scalar Multiplication - non member overload");
}

// Point2D operator *(const double& rh);
void TestScalarMultiplication_Member()
{
    double multiple = 1.5;
    Point2D expected = Point2D(6, -9), point = Point2D(4, -6);
    Point2D actual = point * multiple;
    Assert::AreEqual(expected, actual, "Test Scalar Multiplication - member overload");
}

// Test Point2D
void RunTestPoint2D()
{
    TestEmptyConstructor();
    TestGreedyConstructor();
    TestCopyConstructor();
    TestAssignmentCopyConstructor();
    TestSetters();
    TestSegmentLength();
    TestMidPoint();
    TestEquality();
    TestInequality();
    TestScalarMultiplication_NonMember();
    TestScalarMultiplication_Member();
}

// Test Functions
void RunTestFunctions()
{

}

// Test Vector2D
void RunTestVector2D()
{
    
}

// Test Vector3D
void RunTestVector3D()
{
    
}

// Test Matrix2D
void RunTestMatrix2D()
{
    
}

// Test Matrix3D
void RunTestMatrix3D()
{
    
}

// Test Matrix4D
void RunTestMatrix4D()
{
    
}

// Test Quaternion
void RunTestQuaternion()
{
    
}

// Test Body
void RunTestBody()
{
    
}

void Passed()
{
    cout << "Tests Passed: \n\t" << TestCounts.pass << "/" << TestCounts.tests << endl;
}

void RunAllTests()
{
    RunTestPoint2D();
    RunTestFunctions();
    RunTestVector2D();
    RunTestVector3D();
    RunTestMatrix2D();
    RunTestMatrix3D();
    RunTestMatrix4D();
    RunTestQuaternion();
    RunTestBody();
}