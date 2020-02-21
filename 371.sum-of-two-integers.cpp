#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        vector<int> v{a,b};
        return accumulate(v.begin(), v.end(), 0);
    }
};
// @lc code=end

