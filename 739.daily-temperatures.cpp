#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n=T.size();
        unordered_map<int,vector<int>> m;
        vector<int> v(n);
        for (long long i = 0; i < n; i++) {
            m[T[i]].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            int mi=INT_MAX;
            for (long long j = T[i]+1; j <= 100; j++){
                for (long long k = 0; k < m[j].size(); k++) {
                    if(m[j][k]>i){
                        mi=min(mi,m[j][k]-i);
                    }
                }
            }
            v[i]=(mi==INT_MAX?0:mi);
        }
        return v;
    }
};
// @lc code=end

