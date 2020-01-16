#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int ret=dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
// @lc code=end

