#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 */

// @lc code=start
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> lines;
        int cur_word_cnt = 0;
        vector<string> words_per_line;
        for(int i=0; i<words.size(); i++){
            if(cur_word_cnt + words_per_line.size() + words[i].length()<=maxWidth){
                words_per_line.push_back(words[i]);
                cur_word_cnt += words[i].length();
            }else{
                string line = justify(words_per_line, maxWidth, cur_word_cnt);
                lines.push_back(line);
                i--;
                cur_word_cnt=0;
                words_per_line={};
            }
        }
        string line = justify(words_per_line, maxWidth, cur_word_cnt, true);
        lines.push_back(line);
        return lines;
    }
    string justify(vector<string>& words, int maxWidth, int word_cnt, bool last = false){
        string ret;
        int word_num = words.size();
        if(last){
            for(int i=0; i<word_num; i++){
                ret += words[i];
                if(ret.length() < maxWidth) ret += ' ';
            }
            ret += string(maxWidth - ret.length(), ' ');
        }else if(word_num==1){
            ret += words[0];
            ret += string(maxWidth-words[0].length(), ' ');;
        }else{
            int space_num = word_num-1;
            int space_cnt = maxWidth - word_cnt;
            int one_space_num = space_cnt / space_num;
            int res_space = space_cnt % space_num;
            for(int i=0; i<word_num; i++){
                ret += words[i];
                if(i==word_num-1) break;
                ret += string(one_space_num, ' ');
                if(res_space-- > 0) ret += ' ';
            }
        }
        return ret;
    }
};
// @lc code=end

