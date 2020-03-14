#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mv;
        for (long long i = 0; i < strs.size(); i++) {
            string tmp=strs[i];
            sort(tmp.begin(), tmp.end());
            mv[tmp].push_back(strs[i]);
        }
        vector<vector<string>> vv(mv.size());
        int i=0;
        for (auto& e: mv) {
            vv[i]=e.second;
            i++;
        }
        return vv;
    }
};
// @lc code=end

