#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=792 lang=cpp
 *
 * [792] Number of Matching Subsequences
 */

// @lc code=start
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> m; // { char : [index] }
        // create index table
        for(int i=0; i<s.size(); i++){
            m[s[i]].push_back(i);
        }
        // search subseq by binary-search in index table
        int ret=0;
        for(string w : words){
            int x = -1;
            bool found = true;
            for(char c : w){
                auto itr = upper_bound(m[c].begin(), m[c].end(), x);
                if(itr == m[c].end()) found = false;
                else x = *itr;
            }
            if(found) ret++;
        }
        return ret;
    }
};
// @lc code=end

