#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int max_area=0;
        for(int h=0; h<m; h++){
            for(int w=0; w<n; w++){
                if(grid[h][w]==1){
                    int area = calcArea(grid, h, w, m, n);
                    max_area=max(max_area, area);
                }
            }
        }
        return max_area;
    }
    int calcArea(vector<vector<int>>& grid, int h, int w, int m, int n){
        int dh[4] = {0, 1, 0, -1};
        int dw[4] = {1, 0, -1, 0};
        queue<pair<int, int>> q;

        int area=1;
        grid[h][w]=-1;
        q.push({h, w});
        while(!q.empty()){
            auto [ch, cw] = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nh = ch + dh[i], nw = cw + dw[i];
                if(nh>=0 && nh<m && nw>=0 && nw<n && grid[nh][nw]==1){
                    q.push({nh, nw});
                    grid[nh][nw]=-1;
                    area++;
                }
            }
        }
        return area;
    }
};
// @lc code=end

