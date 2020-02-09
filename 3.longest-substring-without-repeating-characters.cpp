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
        int ret=0, last=0;
        for (int i = 0; i < s.length(); i++) {
            if(m[s[i]]!=0) {
                // last=i;
                ret=max(ret, i-last+1);
                if(last<=m[s[i]]){
                    // ret=max(ret, i-m[s[i]]);
                    last=m[s[i]];
                    while(m[s[last]]!=last+1&&s[last]!=s[i]) last++;
                }
            }else{
                ret=max(ret, i-last+1);
            }
            m[s[i]]=i+1;
            cout << "i: " << i << " ";
            cout << "s[i]: " << s[i] << " ";
            cout << "m[s[i]]: " << m[s[i]] << " ";
            cout << "last: " << last << " ";
            cout << "ret: " << ret << endl;
        }
        return ret;
    }
};
// @lc code=end

