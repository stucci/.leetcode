#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi=INT_MAX, sum=0;
        for (size_t i = 0; i < prices.size(); i++) {
            if(mi>prices[i]){
                mi=prices[i];
            }else{
                sum+=(prices[i]-mi);
                if(i+1<prices.size() && prices[i]<prices[i+1]){
                    mi=prices[i];
                }else{
                    mi=INT_MAX;
                }
            }
        }
        return sum;
    }
};
// @lc code=end

