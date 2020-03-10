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
    void rotate(vector<vector<int>>& matrix) {
        for (long long i = 0; i < matrix[0].size()/2; i++) {
            // rotateRec(matrix, i);
            int beg=i;
            int end=matrix[0].size()-1-beg;
            for (long long i = 0; i < end-beg; i++) {
                swap(matrix[beg][i+beg],matrix[beg+i][end]);
                swap(matrix[beg][i+beg],matrix[end][end-i]);
                swap(matrix[beg][i+beg],matrix[end-i][beg]);
            }
        }
    }
    void rotateRec(vector<vector<int>>& matrix, int idx) {
        int beg=idx;
        int end=matrix[0].size()-1-idx;
        for (long long i = 0; i < end-beg; i++) {
            swap(matrix[beg][i+beg],matrix[beg+i][end]);
            swap(matrix[beg][i+beg],matrix[end][end-i]);
            swap(matrix[beg][i+beg],matrix[end-i][beg]);
        }
    }
};
// @lc code=end

