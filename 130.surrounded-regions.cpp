#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// approach
// 1. search all cells on the boader.
// 2. if I check O cell, searching conected O cells by BFS and recode connected flag to the table.
// 3. seaching all cells, and change O cell to X cell by checking above table.

// constraints
// max height: 200
// max width: 200

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<int> dh = {0, 1, 0, -1};
        vector<int> dw = {1, 0, -1, 0};

        queue<pair<int, int>> q; // {height idx, width idx}
        // step 1
        for(int i=0; i<m; i++){
            int dj=1;
            if(i!=0 && i!=m-1) dj=n-1;
            for(int j=0; j<n; j+=dj){
                if(board[i][j]!='O') continue;
                // step 2
                q.push({i, j});
                board[i][j] = 'C';
                while(!q.empty()){
                    auto [h, w] = q.front();
                    q.pop();
                    for(int k=0; k<4; k++){
                        int nh = h+dh[k], nw = w+dw[k];
                        if(0<=nh&&nh<m && 0<=nw&&nw<n && board[nh][nw]=='O'){
                            q.push({nh, nw});
                            board[nh][nw] = 'C';
                        }
                    }
                }
            }
        }
        // step 3
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'C'){
                    board[i][j] = 'O';
                }else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};
// @lc code=end

