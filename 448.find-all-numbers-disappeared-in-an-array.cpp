#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> v;
        for (int i = 0; i < nums.size(); i++) {
            int idx=abs(nums[i])-1;
            nums[idx]=-abs(nums[idx]);
        }
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i]>0) v.push_back(i+1);
        }
        return v;
    }
};
// @lc code=end

