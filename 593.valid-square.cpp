#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=593 lang=cpp
 *
 * [593] Valid Square
 */

// @lc code=start
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(p1==p2 || p1==p3 || p1==p4 || p2==p3 || p2==p4 || p3==p4) return false;
        return (checkSquare(p1,p2,p3,p4) && checkSquare(p2,p1,p3,p4) && checkSquare(p3,p1,p2,p4));
    }
    int getDist(vector<int>& p1, vector<int>& p2) {
        return (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]);
    }
    bool checkSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> dists = {getDist(p1, p2), getDist(p1, p3), getDist(p1, p4)};
        sort(dists.begin(), dists.end());
        return (dists[0]==dists[1] && dists[0] * 2 == dists[2]);
    }
};
// @lc code=end

