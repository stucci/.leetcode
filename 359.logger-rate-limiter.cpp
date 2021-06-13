#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=359 lang=cpp
 *
 * [359] Logger Rate Limiter
 */

// @lc code=start
class Logger {
public:
    map<string, int> logs;
    /** Initialize your data structure here. */
    Logger() {
        
    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(logs[message]>timestamp){
            return false;
        }else{
            logs[message] = timestamp + 10;
            return true;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
// @lc code=end

