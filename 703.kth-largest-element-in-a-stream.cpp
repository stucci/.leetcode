#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start
class KthLargest {
public:
    int k;
    vector<int> v;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for (auto& e: nums) {
            this->v.push_back(e);
        }
    }
    int add(int val) {
        v.push_back(val);
        sort(v.begin(), v.end());
        return v[v.size()-k];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

