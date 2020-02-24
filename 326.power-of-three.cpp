#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfThree(int n) {
        double e=log10(n)/log10(3);
        return fmod(e,1.0) == 0;
    }
    bool isPowerOfThreeLoopIteration(int n) {
        if(n==0) return false;
        if(n==1) return true;
        while(n%3==0){
            n/=3;
            if(n==1) return true;
        }
        return false;
    }
};
// @lc code=end

