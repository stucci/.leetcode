#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] Count Square Submatrices with All Ones
 */

// @lc code=start
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int ret=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==1 && i>=1 && j>=1){
                    matrix[i][j] += min({matrix[i-1][j-1], matrix[i][j-1], matrix[i-1][j]});
                }
                ret += matrix[i][j];
            }
        }
        return ret;
    }
};
// @lc code=end

