#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    // [A common method to rotate the image - LeetCode Discuss](https://leetcode.com/problems/rotate-image/discuss/18872/A-common-method-to-rotate-the-image)
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for (long long i = 0; i < matrix.size(); i++) {
            for (long long j = i+1; j < matrix[i].size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    void rotateInit(vector<vector<int>>& matrix) {
        for (long long i = 0; i < matrix[0].size()/2; i++) {
            int beg=i;
            int end=matrix[0].size()-1-beg;
            for (long long i = 0; i < end-beg; i++) {
                swap(matrix[beg][i+beg],matrix[beg+i][end]);
                swap(matrix[beg][i+beg],matrix[end][end-i]);
                swap(matrix[beg][i+beg],matrix[end-i][beg]);
            }
        }
    }
};
// @lc code=end

