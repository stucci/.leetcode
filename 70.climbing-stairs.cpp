#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        long long s=0;
        for (size_t i = 0; i <= n/2; i++) {
            s+=nCr(n-i,i);
        }
        return s;
    }
    long long nCr(const long long n, const long long k) {
        if (n < 0) return 0;
        if (k < 0) return 0;
        long long ret = 1;
        for (long long i = 0; i < k; i++) {
            ret *= (long long)n - (long long)i;
            ret /= (long long)(i+1);
        }
        return ret;
    }
};
// @lc code=end

