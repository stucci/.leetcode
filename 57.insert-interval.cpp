#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        map<int, int> m;
        for(auto inter : intervals){
            int start = inter[0];
            int end = inter[1];
            m[start]++;
            m[end]--;
        }
        m[newInterval[0]]++;
        m[newInterval[1]]--;

        vector<vector<int>> ret;
        int cnt = 0, start = 0;
        for(auto [time, sig] : m){
            if(cnt==0 && sig>=1) start = time;
            if(cnt==0 && sig==0) {
                ret.push_back({time, time});
                continue;
            }
            cnt += sig;
            if(cnt==0) ret.push_back({start, time});
        }
        return ret;
    }
};
// @lc code=end

