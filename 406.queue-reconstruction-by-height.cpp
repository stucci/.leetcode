#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        sort(people.begin(), people.end());
        // for (long long i = 0; i < people.size(); i++) {
        //     cout << people[i][0] << endl;
        // }
        vector<vector<int>> v(n, vector<int>(2, -1));
        for (long long i = 0; i < n; i++) {
            int cnt=0;
            for (long long j = 0; j < n; j++) {
                if(v[j][0]==-1 || v[j][0]==people[i][0]){
                    if(cnt==people[i][1]){
                        v[j]=people[i];
                        break;
                    }
                    cnt++;
                }
            }
        }
        return v;
    }
};
// @lc code=end

