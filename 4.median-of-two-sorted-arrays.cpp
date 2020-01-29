#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(), nums1.end());
        double ret;
        if(nums1.size()%2){
            ret=nums1[(nums1.size()-1)/2];
        }else{
            ret=(nums1[(nums1.size())/2-1]+nums1[nums1.size()/2])/2.0;
        }
        return ret;
    }
};
// @lc code=end

