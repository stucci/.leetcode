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
        int j=0;
        for (size_t i = 0; i < t.size() && j<s.size(); i++) {
            if(t[i]==s[j]) j++;
        }
        return j==s.length();
    }
};
// @lc code=end

