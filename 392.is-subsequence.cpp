#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s=="" && t=="") return true;
        if(t=="") return false;
        int j=0;
        for (size_t i = 0; i < s.size(); i++) {
            while(1){
                if(s[i]==t[j]) {
                    j++;
                    break;
                }
                j++;
                if(j>=t.size()) return false;
            }
        }
        return true;
    }
};
// @lc code=end

