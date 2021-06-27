#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=418 lang=cpp
 *
 * [418] Sentence Screen Fitting
 */

// approach
// 1. naive

// QA
// sentence[i].length >= cols ?
// answer 0 はありえるか？
// 文字列は英文字のみか？
// 空文字列はあるか？
// 回答は切り捨てで行うのか？
// sentence.size()?
// max rows? max cols?

// edge cases
// ["a"], rows=1, cols=1 -> 1

// @lc code=start
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        unordered_map<int, int> m;
        int word_total_cnt = 0, sen_siz = sentence.size();
        for(int i=0; i<rows; i++){
            int start_idx = word_total_cnt % sen_siz;
            if(m[start_idx]) {
                word_total_cnt += m[start_idx];
                continue;
            }
            int word_cnt = 0, line_len = 0, sen_idx = start_idx;
            while(cols >= line_len){
                if(line_len + sentence[sen_idx].size() > cols) break;
                line_len += sentence[sen_idx].size() + 1;
                sen_idx++;
                word_cnt++;
                sen_idx %= sen_siz;
            }
            word_total_cnt += word_cnt;
            m[start_idx] = word_cnt;
        }
        return word_total_cnt / sen_siz;
    }
};
// @lc code=end

// test cases
// ["a", "bcd", "e"]\n3\n6
// ["f","p","a"]\n8\n7