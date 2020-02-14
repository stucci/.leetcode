#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="") return 0;
        for (size_t i = 0; i < haystack.length(); i++) {
            int j=0;
            while(haystack[i+j]==needle[j]){
                j++;
                if(j==needle.length()) return i;
                if(i+j==haystack.length()) return -1;
            }
        }
        return -1;
    }
};
// @lc code=end

