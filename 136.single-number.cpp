#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int s=0;
        for (auto& e: nums) s^=e;
        return s;
    }
};
// @lc code=end

