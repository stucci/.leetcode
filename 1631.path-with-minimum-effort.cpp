#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1631 lang=cpp
 *
 * [1631] Path With Minimum Effort
 */

// QA
// int type?
// max row? max column?

// edge case
// [[1]]

// @lc code=start
class Solution {
public:
    vector<int> dy = {0, 1,  0, -1};
    vector<int> dx = {1, 0, -1,  0};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int lo = -1, hi = 1e6+1;
        while(hi-lo>1){
            int mid = (lo+hi)/2;
            if(canPass(heights, mid)){
                hi = mid;
            }else{
                lo = mid;
            }
        }
        return hi;
    }
    bool canPass(vector<vector<int>>& heights, int effort){
        int row = heights.size();
        int col = heights[0].size();
        if(row==1 && col==1) return true;
        vector<vector<bool>> seen(row, vector<bool>(col, false));

        queue<pair<int, int>> q; // {y, x}
        q.push({0, 0});
        seen[0][0] = true;
        while(!q.empty()){
            auto [y, x] = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int ny = y+dy[i], nx = x+dx[i];
                if(0<=ny&&ny<row && 0<=nx&&nx<col && abs(heights[ny][nx]-heights[y][x])<=effort && seen[ny][nx]==false){
                    q.push({ny, nx});
                    seen[ny][nx] = true;
                    if(ny==row-1 && nx==col-1) return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

