#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());
        v.push_back(nums);
        while(next_permutation(nums.begin(), nums.end())){
            v.push_back(nums);
        }
        return v;
    }
};
// @lc code=end

