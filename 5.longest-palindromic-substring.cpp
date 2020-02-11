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
        for (int i = 0; i < s.length(); i++) {
            for (int j = 1; i+j <= s.length(); j++) {
                string t=s.substr(i,j);
                if(t==string(t.rbegin(),t.rend())){
                    if(r.length()<t.length()){
                        r=t;
                    }
                }
                cout << "t: " << t << endl;
            }
        }
        return r;
    }
};
// @lc code=end

