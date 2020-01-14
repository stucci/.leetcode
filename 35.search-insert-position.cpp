#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // int lo=0, hi=nums.size();
        // while(hi-lo>1){
        //     int mid=(hi+lo)/2;
        //     if(nums[mid]>target) hi = mid;
        //     else lo = mid;
        // }
        // return lo+(nums[lo]<target);
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
// @lc code=end

