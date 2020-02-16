#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string s) {
        int sum=0;
        int n=s.length();
        for (int i = n-1; i >= 0; i--) {
            int d=(s[i]-'A'+1);
            sum+=(pow(26,n-1-i)*d);
        }
        return sum;
    }
};
// @lc code=end

