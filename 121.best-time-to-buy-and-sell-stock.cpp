#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi=INT_MAX, ma=0;
        for(int i = 0; i < prices.size(); i++)
            mi>prices[i] ? mi=prices[i] : ma=max(ma,prices[i]-mi);
        return ma;
    }
};
// @lc code=end

