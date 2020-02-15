#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        string t=regex_replace(s,regex("[^a-z0-9]"),"");
        return (t==string(t.rbegin(),t.rend()));
    }
};
// @lc code=end

