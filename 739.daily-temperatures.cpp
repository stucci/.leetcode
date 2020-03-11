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
        vector<int> v(T.size());
        stack<int> s;
        for (int i = T.size() - 1; i >= 0; i--) {
            while(s.empty()==false && T[i]>=T[s.top()]) s.pop();
            v[i]=(s.empty()?0:s.top()-i);
            s.push(i);
        }
        return v;
    }
    vector<int> dailyTemperaturesNextArray(vector<int>& T) {
        vector<int> v(T.size());
        vector<int> next(101,INT_MAX);
        for (int i = T.size() - 1; i >= 0; i--) {
            int warmer_index=INT_MAX;
            for (int t = T[i]+1; t <= 100; t++) {
                if(next[t]<warmer_index) warmer_index=next[t];
            }
            if(warmer_index<INT_MAX) v[i]=warmer_index-i;
            next[T[i]]=i;
        }
        return v;
    }
};
// @lc code=end

