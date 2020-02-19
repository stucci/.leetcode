#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int s=0;
        while(n){
            s+=(n&1);
            n>>=1;
        }
        return s;
    }
};
// @lc code=end

