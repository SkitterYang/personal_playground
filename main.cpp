#include <iostream>

#include "ywy/log.h"
#include "leetcode/leetcode.h"

#include <sstream>

int main() {
    // leetcode::UnitTester tester;
    // tester.shortestSubarraytest();
    typedef unsigned int mask;
    mask testInt = 1 << 12;
    std::stringstream logss;

    testInt = ~0;
    logss << testInt;

    LOG("NOTICE",logss.str().c_str());
    logss.str("");

    return 0;
}
