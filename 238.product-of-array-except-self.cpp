#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> l(n);
        vector<int> r(n);
        vector<int> v(n);
        l[0]=1;
        r[n-1]=1;
        for (long long i = 1; i < n; i++) {
            l[i]=l[i-1]*nums[i-1];
            r[n-1-i]=r[n-i]*nums[n-i];
        }
        for (long long i = 0; i < n; i++) {
            v[i]=l[i]*r[i];
        }
        return v;
    }
};
// @lc code=end

