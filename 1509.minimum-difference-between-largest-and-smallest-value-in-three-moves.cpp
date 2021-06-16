#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1509 lang=cpp
 *
 * [1509] Minimum Difference Between Largest and Smallest Value in Three Moves
 */

// @lc code=start
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n<=4) return 0;
        sort(nums.begin(), nums.end());

        int min_diff = nums[n-4] - nums[0];
        for(int i=1; i<=3; i++){
            min_diff = min(min_diff, nums[n-4+i] - nums[i]);
        }
        return min_diff;
    }
};
// @lc code=end

