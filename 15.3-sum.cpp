#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if(i>0&&nums[i]==nums[i-1]) continue;
            int lo=i+1, hi=nums.size()-1;
            while(hi-lo>0){
                int sum=nums[i]+nums[lo]+nums[hi];
                if(sum==0){
                    ret.push_back({nums[i],nums[lo],nums[hi]});
                    while(lo<nums.size()-1 && nums[lo]==nums[lo+1]) lo++;
                    while(hi>0 && nums[hi]==nums[hi-1]) hi--;
                    lo++,hi--;
                }else if(sum>0){
                    hi--;
                }else{
                    lo++;
                }
            }
        }
        return ret;
    }
};
// @lc code=end

