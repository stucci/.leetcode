#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> m;
        int ret=0,i=0,j=0;
        while(i<s.length()&&j<s.length()){
            if(m.count(s[j])==0){
                m[s[j]]++;
                j++;
                ret=max(ret,j-i);
            }else{
                m.erase(s[i]);
                i++;
            }
            // cout << "s[i]: " << s[i] << ", ";
            // cout << "s[j]: " << s[j] << ", ";
            // cout << "j-i: " << j-i << ", ";
            // for(auto& e: m) cout << "    " << e.first<<":"<<e.second << ", ";
            // cout<<endl;
        }
        return ret;
    }
};
// @lc code=end

