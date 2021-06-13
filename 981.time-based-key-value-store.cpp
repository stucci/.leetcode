#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
// class TimeMap {
// public:
//     /** Initialize your data structure here. */
//     map<string, vector<int>> key_timestamp_map;
//     map<int, string> timestamp_value_map;
//     TimeMap() {
        
//     }
    
//     void set(string key, string value, int timestamp) {
//         key_timestamp_map[key].push_back(timestamp);
//         timestamp_value_map[timestamp] = value;
//     }
    
//     string get(string key, int timestamp) {
//         vector<int> *target = &key_timestamp_map[key];
//         auto itr = upper_bound((*target).begin(), (*target).end(), timestamp);
//         if(itr == (*target).begin()) return "";
//         int timestamp_prev = *prev(itr);
//         return timestamp_value_map[timestamp_prev];
//     }
// };

class TimeMap {
public:
    /** Initialize your data structure here. */
    // {key, {timestamp, value} }
    unordered_map<string, map<int, string>> time_map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        time_map[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto itr = time_map[key].upper_bound(timestamp);
        if(itr == time_map[key].begin()) return "";
        else return prev(itr)->second;
    }
};
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end

