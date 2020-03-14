#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int gauss=n*(n+1)/2;
        int sum=accumulate(nums.begin(), nums.end(),0);
        return n-(gauss-sum);
    }
};
// @lc code=end

