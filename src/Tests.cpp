// This is where tests will be performed on the math and physics
#pragma once
#include "tests.h"

enum Test
{
    Test_Point2D,
    Test_Functions,
    Test_Default
};

Test ParseCommandLine(char *argv[])
{
    const char * args = *argv;
    Test t = Test::Test_Default;
    if(args == "point2") { t = Test::Test_Point2D; }
    else if(args == "function") { t = Test::Test_Functions; }
    else {}
    return t;
}

int main(int argc, char *argv[])
{
    const char * args = *argv;
    // Take command line args, parse, switch determine which set of sets to run, default to all tests.
    switch(ParseCommandLine(argv))
    {
        case Test::Test_Point2D:
        RunTestPoint2D();
        break;
        default:
        RunAllTests();
        break;
    }
    Passed();
    // pause before ending
    system("pause"); // Not the best approach...
}

