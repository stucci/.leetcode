#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ret(1<<n);
        for (int bit = 0; bit < (1<<n); bit++) {
            for (int i = 0; i < n; i++) {
                if(bit & (1<<i)) ret[bit].push_back(nums[i]);
            }
        }
        return ret;
    }
    vector<vector<int>> subsetsInit(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ret;
        for (int bit = 0; bit < (1<<n); bit++) {
            vector<int> v;
            for (int i = 0; i < n; i++) {
                if(bit & (1<<i)) {
                    v.push_back(nums[i]);
                }
            }
            ret.push_back(v);
        }
        return ret;
    }
};
// @lc code=end

