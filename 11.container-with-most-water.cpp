#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area=0;
        int i=0,j=height.size()-1;
        while(i!=j){
            int area=(j-i)*min(height[i],height[j]);
            max_area=max(max_area,area);
            height[i]<height[j] ? i++ : j--;
        }
        return max_area;
    }
};
// @lc code=end

