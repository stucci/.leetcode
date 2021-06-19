#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=843 lang=cpp
 *
 * [843] Guess the Word
 */

// @lc code=start
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int match_num=0;
        for(int i=0; i<10; i++){
            // matchして0が帰ってくるもの、つまり、最もマッチしていない文字列
            // つまり、w1がどれだけ他の文字列と遠いかをカウントする。
            // 「最も仲間外れな文字列度」を求める
            unordered_map<string, int> count;
            for(auto w1 : wordlist){
                for(auto w2 : wordlist){
                    if(match(w1, w2) == 0){
                        count[w1]++;
                    }
                }
            }
            // 最も「仲間はずれ度合い」が小さなwordを求める。
            pair<string, int> minimax = {wordlist[0], 1000};
            for(string w : wordlist){
                if(count[w] <= minimax.second){
                    minimax = {w, count[w]};
                }
            }
            // 最も「仲間はずれ度合い」が小さいwordで試しにguessしてみる。
            match_num = master.guess(minimax.first);
            if(match_num==6) return;
            // guessした文字列と同じマッチ数の文字列を次の探索候補とする。
            vector<string> wordlist_next;
            for(string w : wordlist){
                if(match(minimax.first, w) == match_num){
                    wordlist_next.push_back(w);
                }
            }
            wordlist = wordlist_next;
        }
    }
    int match(string a, string b) {
        int matches = 0;
        for (int i = 0; i < a.length(); ++i)
            if (a[i] == b[i])
                matches ++;
        return matches;
    }
};
// @lc code=end

