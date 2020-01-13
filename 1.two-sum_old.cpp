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
    vector<int> twoSum_BruteForce(vector<int>& nums, int target) {
        vector<int> v(2);
        bool f = false;
        for (int i = 0; i < nums.size(); i++){
            for (int j = i+1; j < nums.size(); j++){
                if (nums[i] + nums[j] == target){
                    v[0]=i;
                    v[1]=j;
                    f = true;
                    break;
                }
            }
            if(f) break;
        }
        return v;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            auto itr = m.find(complement);
            if(itr != m.end() && itr->second!=i){
                vector<int> v = {i, itr->second};
                return v;
            }
        }
        return vector<int>();
    }
};
// @lc code=end

