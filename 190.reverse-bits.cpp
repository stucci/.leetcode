#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret=0;
        for (long long i = 0; i < 32; i++) {
            int lsb=n&1;
            ret<<=1;
            ret|=lsb;
            n>>=1;
        }
        return ret;
    }
};
// @lc code=end

