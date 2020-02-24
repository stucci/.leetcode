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
        int n=nums.size();
        int expected_sum=n*(n+1)/2;
        int sum=accumulate(nums.begin(), nums.end(),0);
        return expected_sum-sum;
    }
    int missingNumberXOR(vector<int>& nums) {
        int missing=nums.size();
        for (long long i = 0; i < nums.size(); i++) {
            missing ^= i^nums[i];
        }
        return missing;
    }
    int missingNumberMap(vector<int>& nums) {
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

