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
        // // initial subumission
        // transform(s.begin(),s.end(),s.begin(),::tolower);
        // string t=regex_replace(s,regex("[^a-z0-9]"),"");
        // return (t==string(t.rbegin(),t.rend()));

        for (int i = 0, j = s.size()-1; i < j; i++,j--) {
            while(!isalnum(s[i]) && i<j) i++;
            while(!isalnum(s[j]) && i<j) j--;
            if(tolower(s[i])!=tolower(s[j])) return false;
        }
        return true;
    }
};
// @lc code=end

