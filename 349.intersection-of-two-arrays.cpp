#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> ret;
        for(auto& e: nums2){
            if(s.count(e)){
                ret.push_back(e);
                s.erase(e);
            }
        }
        return ret;
    }
};
// @lc code=end

