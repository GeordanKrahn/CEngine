// This is where tests will be performs on the math and physics
#pragma once
#include "tests.h"

int main(int argc, char *argv[])
{
    // Take command line args, parse, switch determine which set of sets to run, default to all tests.
    RunAllTests();


    // pause before ending
    system("pause"); // Not the best approach...
}