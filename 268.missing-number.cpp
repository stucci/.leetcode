#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,bool> um;
        for (long long i = 0; i < nums.size(); i++) {
            um[nums[i]]=true;
        }
        for (long long i = 0; i <= nums.size(); i++) {
            if(um[i]==false) return i;
        }
        return -1;
    }
};
// @lc code=end

