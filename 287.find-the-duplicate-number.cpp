#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for (long long i = 1; i <= n; i++) {
            int cnt=0;
            for (long long j = 0; j < n; j++) {
                if(i==nums[j]) cnt++;
                if(cnt>1) return i;
            }
        }
        return 0;
    }
};
// @lc code=end

