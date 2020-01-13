#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            auto itr = m.find(complement);
            if(itr != m.end()) return vector<int>{itr->second, i};
            m[nums[i]] = i;
        }
        return vector<int>();
    }
};
// @lc code=end

