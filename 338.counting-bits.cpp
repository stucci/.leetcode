#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v(num+1);
        for (long long i = 1; i <= num; i++) {
            int l=floor(log2(i));
            int d=pow(2,l);
            v[i]=v[i-d]+1;
        }
        return v;
    }
};
// @lc code=end

