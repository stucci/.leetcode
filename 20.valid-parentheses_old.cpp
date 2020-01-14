#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i]=='('||s[i]=='['||s[i]=='{') {
                st.push(s[i]);
            }else if(st.size()!=0){
                char c = st.top();
                if((c=='('&&s[i]==')')||(c=='['&&s[i]==']')||(c=='{'&&s[i]=='}')) {
                    st.pop();
                    continue;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
        if(st.size()!=0){
            return false;
        }else{
            return true;
        }
    }
};
// @lc code=end

