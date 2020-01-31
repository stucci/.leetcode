#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        string str="1";
        while(--n){
            string tmp="";
            int j=0;
            for (size_t i = 0; i < str.size();) {
                while(j<str.size() && str[i]==str[j]) j++;
                tmp+=(to_string(j-i)+str[i]);
                i=j;
            }
            str=tmp;
        }
        return str;
    }
};
// @lc code=end

