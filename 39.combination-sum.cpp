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
        vector<int> t;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, v, t);
        return v;
    }
    void helper(vector<int>& candidates, int target, int index,  vector<vector<int>>& v, vector<int> t){
        if(target==0){
            v.push_back(t);
            return;
        }
        for (long long i = index; i < candidates.size() && target-candidates[i]>=0; i++) {
            t.push_back(candidates[i]);
            helper(candidates, target-candidates[i], i, v, t);
            t.pop_back();
        }
    }
};
// @lc code=end

