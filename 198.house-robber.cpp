#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(100, -1);
        return dfs(nums, dp, 0);
    }
    int dfs(vector<int>& nums, vector<int>& dp, int i){
        if(nums.size()<=i) return 0;
        if(nums.size()<=i+1) return nums[i];
        if(nums.size()<=i+2) return max(nums[i], nums[i+1]);
        if(nums.size()<=i+3) return max(nums[i]+nums[i+2], nums[i+1]);
        if(dp[i]==-1) dp[i] = max(nums[i]+dfs(nums, dp, i+2), nums[i+1]+dfs(nums, dp, i+3));
        return dp[i];
    }
};
// @lc code=end

