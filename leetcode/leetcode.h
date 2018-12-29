#ifndef LEETCODE_LEETCODE_H
#define LEETCODE_LEETCODE_H

#include <vector>

namespace leetcode{
    void log();
    
    class UnitTester {
    public:
        UnitTester() {}
        ~UnitTester() {}
        int test();
        int shortestSubarraytest();
    };

    class Solution {
    public:
        int shortestSubarray(std::vector<int>& A, int K);
    };
}

#endif // LEETCODE_LEETCODE_H
