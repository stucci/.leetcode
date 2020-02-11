#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        string r="";
        int n=s.length();
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if(s[i]==s[j] && (j-i<3 || dp[i+1][j-1])) {
                    dp[i][j]=true;
                }
                if(dp[i][j]==true && (j-i+1)>r.length()){
                    r=s.substr(i, j-i+1);;
                }
            }
        }
        return r;
    }
};
// @lc code=end

