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
        for (auto& e : s) {
            if (e=='('||e=='['||e=='{') {
                st.push(e);
            }else{
                if(st.empty()) return false;
                char c = st.top();
                if(!((c=='('&&e==')')||(c=='['&&e==']')||(c=='{'&&e=='}'))) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
// @lc code=end

