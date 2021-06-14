#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=246 lang=cpp
 *
 * [246] Strobogrammatic Number
 */

// @lc code=start
class Solution {
public:
    bool isStrobogrammatic(string num) {
        int len = num.size();
        bool ret = true;
        for(int i=0; i<len/2; i++){
            if(num[i]=='0' && num[len-1-i]=='0') continue;
            if(num[i]=='1' && num[len-1-i]=='1') continue;
            if(num[i]=='8' && num[len-1-i]=='8') continue;
            if(num[i]=='6' && num[len-1-i]=='9') continue;
            if(num[i]=='9' && num[len-1-i]=='6') continue;
            ret = false;
            break;
        }
        if(len%2){
            int mid = num[len/2];
            if(mid != '0' && mid != '1' && mid != '8') ret = false;
        }
        return ret;
    }
};
// @lc code=end

