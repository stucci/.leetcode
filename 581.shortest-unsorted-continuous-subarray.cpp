#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 */

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted_nums=nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        int first=nums.size(), last=0;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i]!=sorted_nums[i]){
                first=min(first,i);
                last=max(last,i);
            }
        }
        return max(last-first+1,0);
    }
};
// @lc code=end

