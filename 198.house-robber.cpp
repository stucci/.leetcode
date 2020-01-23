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
        vector<int> dp(1000);
        return dfs(nums, dp, 0);
        // if(nums.size()<=0) return 0;
        // if(nums.size()<=1) return nums[0];
        // if(nums.size()<=2) return max(nums[0], nums[1]);
        // if(nums.size()<=3) return max(nums[0]+nums[2], nums[1]);
        // vector<int> first(nums.begin()+2, nums.end());
        // vector<int> second(nums.begin()+3, nums.end());
        // return max(nums[0]+rob(first), nums[1]+rob(second));
    }
    int dfs(vector<int>& nums, vector<int>& dp, int begin){
        if(nums.size()<=begin) return 0;
        if(nums.size()<=begin+1) return nums[begin];
        if(nums.size()<=begin+2) return max(nums[begin], nums[begin+1]);
        if(nums.size()<=begin+3) return max(nums[begin]+nums[begin+2], nums[begin+1]);
        // vector<int> first(nums.begin()+2, nums.end());
        // vector<int> second(nums.begin()+3, nums.end());
        return max(nums[begin]+dfs(nums, dp, 2), nums[begin+1]+dfs(nums, dp, 3));
    }
};
// @lc code=end

