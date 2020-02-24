#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // unordered_set<int> s(nums.begin(), nums.end());
        // return s.size()!=nums.size();
        return nums.size()!=unordered_set<int>(nums.begin(), nums.end()).size();
    }
};
// @lc code=end

