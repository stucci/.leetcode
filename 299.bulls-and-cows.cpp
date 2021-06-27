#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=299 lang=cpp
 *
 * [299] Bulls and Cows
 */

// approarch
// 1. naive approach
// 2. store to hash table -> calc cows

// QA
// secret length? guess length?
// secret length is same as guess length?
// secret and guess consists of digits only?

// edge case
// 1234 1234 -> 4A0B
// 1234 4321 -> 0A4B
// 1111 2222 -> 0A0B

// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> secret_map;
        unordered_map<char, int> guess_map;
        int bulls_num = 0;
        for(int i=0; i<secret.size(); i++){
            if(secret[i]==guess[i]) {
                bulls_num++;
            } else {
                secret_map[secret[i]]++;
                guess_map[guess[i]]++;
            }
        }
        int cows_num = 0;
        for(auto [c, n] : guess_map){
            cows_num += min(n, secret_map[c]);
        }
        string ret = to_string(bulls_num) + 'A' + to_string(cows_num) + 'B';
        return ret;
    }
};
// @lc code=end

