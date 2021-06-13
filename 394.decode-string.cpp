// #include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        int index = 0;
        return helper(s, index);
    }
    string helper(string s, int& index){
        string decoded;
        while(index < s.length() && s[index] != ']'){
            if(!isdigit(s[index])){
                decoded += s[index];
                index++;
            }else{
                int k=0;
                while(index < s.length() && isdigit(s[index])){
                    k = k*10 + s[index] - '0';
                    index++;
                }
                index++; // ignore [
                string ret = helper(s, index);
                index++; // ignore ]
                while(k>0){
                    decoded += ret;
                    k--;
                }
            }
        }
        return decoded;
    }
};
// @lc code=end

