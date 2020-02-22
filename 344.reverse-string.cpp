#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        char tmp;
        for (long long i = 0; i < s.size()/2; i++) {
            tmp=s[i];
            s[i]=s[s.size()-1-i];
            s[s.size()-1-i]=tmp;
        }
    }
};
// @lc code=end

