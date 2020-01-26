#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_multiset<char> ums(s.begin(), s.end());
        int ret=-1;
        for (size_t i = 0; i < s.length(); i++) {
            if(ums.count(s[i])==1) {
                ret=i;
                break;
            }
        }
        return ret;
    }
};
// @lc code=end

