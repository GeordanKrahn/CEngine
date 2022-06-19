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
        auto timerStart = chrono::steady_clock::now();
        bool isRunning = false, isEqual = expected == actual;
        auto msg = [&]()->void { cout << "Test " << (!isRunning ? TestCounts.tests : ++TestCounts.tests) << ": " << (isRunning ? "Running " : "Finished ") << testName << endl; };
        auto output = [&]()->void
        {
            cout << (isEqual ? "Test Passed" : "Test Failed") << "\n" << "Expected:" << expected << "\n" << "Actual:" << actual << endl;
            TestCounts.pass = isEqual ? ++TestCounts.pass : TestCounts.pass;
        };
        isRunning = true;
        msg();
        output();
        isRunning = false;
        msg();
        auto timerEnd = chrono::steady_clock::now();
        auto difference = (timerEnd - timerStart).count();
        cout << "Test completed in: " << difference << " ns\n" << endl;
    };
};

// Run Point2D Tests
void TestEmptyConstructor()
{
    Point2D actual = Point2D();
    Point2D expected = Point2D(0, 0);
    Assert::AreEqual(expected, actual, "Test Empty Constructor");
}

void TestGreedyConstructor()
{
    Point2D expected = Point2D(3.1415,7.777777);
    double x = 3.1415, y = 7.777777;
    Point2D actual = Point2D(x, y);
    Assert::AreEqual(expected, actual, "Test Greedy Constructor");
}

void TestCopyConstructor()
{
    Point2D expected = Point2D(15.24, 67.43333);
    Point2D point = Point2D(15.24, 67.43333);
    Point2D actual = Point2D(point);
    Assert::AreEqual(expected, actual, "Test Copy Constructor");
}

void TestAssignmentCopyConstructor()
{
    Point2D expected = Point2D(15.24, 67.43333);
    Point2D point = Point2D(15.24, 67.43333);
    Point2D actual = point;
    Assert::AreEqual(expected, actual, "Test Copy Assignment Constructor");
}

void TestSetters()
{
    double x = 12.4334, y = 53.333444;
    Point2D expected = Point2D(12.4334, 53.333444);
    Point2D actual = Point2D();
    actual.SetX(x);
    actual.SetY(y);
    Assert::AreEqual(expected, actual, "Test Setters");
}

void TestSegmentLength()
{
    double expected = 5;
    Point2D a = Point2D(0, 0), b = Point2D(3, 4);
    double actual = a.SegmentLength(b);
    Assert::AreEqual(expected, actual, "Test Segment Length");
}

void TestMidPoint()
{
    Point2D a = Point2D(0, 0), b = Point2D(-3, 4), expected = Point2D(-1.5, 2);
    Point2D actual = a.MidPoint(b);
    Assert::AreEqual(expected, actual, "Test Mid Point");
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

    // Test Equality

    // Test Inequality

    // Test Scalar Multiplication

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
    Passed();
}