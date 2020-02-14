#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v(numRows);
        if(numRows==0) return v;
        v[0].push_back(1);
        for (size_t i = 1; i < numRows; i++) {
            v[i].push_back(1);
            for (size_t j = 0; j < v[i-1].size(); j++) {
                int s=v[i-1][j]+(j+1<v[i-1].size()?v[i-1][j+1]:0);
                v[i].push_back(s);
            }
        }
        return v;
    }
};
// @lc code=end

