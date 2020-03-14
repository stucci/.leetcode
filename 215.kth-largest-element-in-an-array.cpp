#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for (long long i = 0; i < nums.size(); i++) {
            q.push(nums[i]);
            if(q.size()>nums.size()-k+1) q.pop();
        }
        return q.top();
    }
};
// @lc code=end

