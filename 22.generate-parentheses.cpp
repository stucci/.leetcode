#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> ret;
    vector<string> generateParenthesis(int n) {
        stack<char> st;
        string s;
        genPare(st,n,s);
        return ret;
    }
    void genPare(stack<char> &st, int n, string s){
        if(n==0 && st.empty()){
            ret.push_back(s);
            return;
        }
        if(st.empty()){
            st.push('(');
            s+='(';
            genPare(st,n-1,s);
        }else if(n!=0){
            stack<char> tmpst=st;
            string tmpstr=s;
            st.push('(');
            s+='(';
            genPare(st,n-1,s);
            tmpst.pop();
            tmpstr+=')';
            genPare(tmpst,n,tmpstr);
        }else{
            st.pop();
            s+=')';
            genPare(st,n,s);
        }
    }
};
// @lc code=end

