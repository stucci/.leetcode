#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1423 lang=cpp
 *
 * [1423] Maximum Points You Can Obtain from Cards
 */

// @lc code=start
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int len = cardPoints.size();
        for(int i=len-k; i<len; i++){
            sum += cardPoints[i];
        }
        int max_sum = sum;
        for(int i=len-k+1; i<len+1; i++){
            sum -= cardPoints[i-1];
            sum += cardPoints[(i-1+k)%len];
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};
// @lc code=end

