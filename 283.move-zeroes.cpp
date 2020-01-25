#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        for (size_t i = 0; i < n; i++) {
            while(nums[i]==0 && i<n){
                nums.erase(nums.begin()+i);
                nums.push_back(0);
                n--;
            }
        }
    }
};
// @lc code=end

