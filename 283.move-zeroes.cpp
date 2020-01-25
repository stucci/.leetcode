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
        for (size_t i = 0, zeropos=0; i < nums.size(); i++) {
            if(nums[i]!=0){
                swap(nums[i], nums[zeropos]);
                zeropos++;
            }
        }
    }
};
// @lc code=end

