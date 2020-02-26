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
        permuteBacktrack(nums, 0, v);
        return v;
    }
    void permuteBacktrack(vector<int> nums, int i, vector<vector<int>> &v){
        if(i==nums.size()){
            v.push_back(nums);
        }else{
            for (long long j = i; j < nums.size(); j++) {
                swap(nums[i], nums[j]);
                permuteBacktrack(nums,i+1,v);
            }
        }
    }
    vector<vector<int>> permuteStd(vector<int>& nums) {
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

