#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int pos=strs[0].size();
        for (size_t i = 1; i < strs.size(); i++) {
            int tmp=0;
            for (size_t j = 0; j < strs[i].size(); j++) {
                if(strs[i-1][j]==strs[i][j]){
                    tmp++;
                }else{
                    break;
                }
            }
            pos=min(pos,tmp);
        }
        return strs[0].substr(0,pos);
    }
};
// @lc code=end

