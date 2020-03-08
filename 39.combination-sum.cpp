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
        helper(candidates, target, 0, v, t);
        return v;
    }
    void helper(vector<int>& candidates, int target, int index,  vector<vector<int>>& v, vector<int> t){
        for (long long i = 0; i < t.size(); i++) {
            cout << "t[i]: " << t[i] << " ";
        }
        cout << "target: " << target << endl;
        if(target==0){
            v.push_back(t);
            return;
        }else if(target<0){
            return;
        }
        for (long long i = index; i < candidates.size(); i++) {
            t.push_back(candidates[i]);
            helper(candidates, target-candidates[i], i, v, t);
            for (long long i = 0; i < t.size(); i++) {
                cout << "t[i]: " << t[i] << " ";
            }
            cout << "target befort popback: " << target << endl;
            t.pop_back();
        }
    }
};
// @lc code=end

