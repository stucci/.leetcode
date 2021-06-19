#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ng = 0, ok = 1e9+1;
        while(ok - ng > 1){
            int mid = (ok+ng)/2;
            int cnt = 0;
            for(int p : piles){
                cnt += ceil(p*1.0/mid);
            }
            if(cnt > h){
                ng = mid;
            }else{
                ok = mid;
            }
        }
        return ok;
    }
};
// @lc code=end

