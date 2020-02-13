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
        unordered_map<int,int> um;
        int s=0;
        for (size_t i = 0; i < nums.size(); i++) {
            if(um[nums[i]]==0){
                um[nums[i]]++;
                s+=nums[i];
            }else{
                s-=nums[i];
            }
        }
        return s;
    }
};
// @lc code=end

