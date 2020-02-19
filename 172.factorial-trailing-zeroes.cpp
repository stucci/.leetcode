#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        int sum=0;
        for (long long i = 1; pow(5,i) <= n; i++) {
            sum+=(n/pow(5,i));
        }
        return sum;
    }
};
// @lc code=end

