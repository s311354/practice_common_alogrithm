#include <iostream>
#include <assert.h>
#include <vector>
#include "./jvector.h"
#include "./jvector_test.h"

void StandardExperiment();

int main(int argc, char *argv[])
{
    common::JvectorTest tester;
    tester.RunTests();

    return 0;
}
