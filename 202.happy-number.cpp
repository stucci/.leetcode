#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        string s=to_string(n);
        unordered_map<string,bool> um;
        um[s]=true;
        while(s!="1"){
            int sum=0;
            for (long long i = 0; i < s.length(); i++) {
                sum+=(s[i]-'0')*(s[i]-'0');
            }
            s=to_string(sum);
            if(um[s]==true){
                return false;
            }else{
                um[s]=true;
            }
        }
        return true;
    }
};
// @lc code=end

