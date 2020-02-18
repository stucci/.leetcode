#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        vector<int> v;
        for (int i = 1; i <= nums.size(); i++) {
            if(s.count(i)==0) v.push_back(i);
        }
        return v;
    }
};
// @lc code=end

