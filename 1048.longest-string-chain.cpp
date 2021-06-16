#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,n) for(int i=x;i<(int)n;++i)
#define vout(v) rep(i,0,v.size())cout<<v[i]<<(i==v.size()-1?"\n":" ");
/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 */

// @lc code=start
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> dp;
        auto cmp = [](string a, string b){return a.length() < b.length();};
        sort(words.begin(), words.end(), cmp);
        // vout(words);

        int max_chain=0;
        for(string word : words){
            int cur_chain=1;
            for(int i=0; i<word.length(); i++){
                string tmp = word;
                tmp.erase(tmp.begin()+i);
                if(dp.find(tmp)!=dp.end()){
                    int prev_chain = dp[tmp];
                    cur_chain = max(cur_chain, prev_chain+1);
                }
            }
            dp[word] = cur_chain;
            max_chain = max(max_chain, cur_chain);
        }
        return max_chain;
    }
};
// @lc code=end

