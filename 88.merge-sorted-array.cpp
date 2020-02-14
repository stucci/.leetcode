#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (size_t i = 0, j=0; i < n; i++) {
            while(j<m && nums2[i]>=nums1[j]) j++;
            for (size_t k = 0; k < m-j; k++) nums1[m-k]=nums1[m-k-1];
            nums1[j]=nums2[i];
            m++;
        }
    }
};
// @lc code=end

