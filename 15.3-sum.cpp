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
        set<vector<int>> s;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                for (int k = j+1; k < nums.size(); k++) {
                    if(nums[i]+nums[j]+nums[k]==0) {
                        vector<int> tmp({nums[i],nums[j],nums[k]});
                        sort(tmp.begin(), tmp.end());
                        s.insert(tmp);
                    }
                }
            }
        }
        vector<vector<int>> v(s.begin(),s.end());
        return v;
    }
};
// @lc code=end

