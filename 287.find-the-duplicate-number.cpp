#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (long long i = 0; i < nums.size(); i++) {
            if(nums[i]==nums[i+1]) return nums[i];
        }
        return 0;
    }
};
// @lc code=end

