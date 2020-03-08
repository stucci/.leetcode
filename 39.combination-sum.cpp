#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        for (long long i = 0; i < candidates.size(); i++) {
            vector<int> t;
            helper(candidates, target, i, v, t);
        }
        return v;
    }
    void helper(vector<int>& candidates, int target, int index,  vector<vector<int>>& v, vector<int> t){
        int nexttarget=target-candidates[index];
        t.push_back(candidates[index]);
        if(nexttarget==0){
            v.push_back(t);
        }else if(nexttarget<0){
            return;
        }
        for (long long i = index; i < candidates.size(); i++) {
            helper(candidates, nexttarget, i, v, t);
        }
    }
};
// @lc code=end

