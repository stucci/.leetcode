#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char, int> ums, umt;
        for (long long i = 0; i < s.length(); i++) {
            ums[s[i]]++;
            umt[t[i]]++;
        }
        return ums==umt;
    }
    bool isAnagramSort(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;
    }
};
// @lc code=end

