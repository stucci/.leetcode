#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        vector<int> v;
        for (auto& e: nums1) m[e]++;
        for (auto& e: nums2) if(m[e]-- > 0) v.push_back(e);
        return v;
    }
    vector<int> intersectMap(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        vector<int> v;
        for (long long i = 0; i < nums1.size(); i++) {
            m[nums1[i]]++;
        }
        for (long long i = 0; i < nums2.size(); i++) {
            if(m[nums2[i]]>0){
                v.push_back(nums2[i]);
                m[nums2[i]]--;
            }
        }
        return v;
    }
};
// @lc code=end

