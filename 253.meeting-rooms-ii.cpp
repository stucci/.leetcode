#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=253 lang=cpp
 *
 * [253] Meeting Rooms II
 */

// @lc code=start
class Solution {
public:
    //// IMOS method
    // int mtgtime[1000001];
    // int minMeetingRooms(vector<vector<int>>& intervals) {
    //     for(auto interval : intervals){
    //         int start = interval[0];
    //         int end = interval[1];
    //         mtgtime[start]+=1;
    //         mtgtime[end]-=1;
    //     }
    //     int mtg_cnt=0, required_room_cnt=0;
    //     for(int i=0; i<1000001; i++){
    //         mtg_cnt += mtgtime[i];
    //         required_room_cnt = max(required_room_cnt, mtg_cnt);
    //     }
    //     return required_room_cnt;
    // }

    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> mtg_map;
        for(auto interval : intervals){
            int start = interval[0], end = interval[1];
            mtg_map[start]++;
            mtg_map[end]--;
        }
        int mtg_cnt=0, max_mtg_cnt=0;
        for(auto mtg : mtg_map){
            mtg_cnt+=mtg.second;
            max_mtg_cnt=max(max_mtg_cnt, mtg_cnt);
        }
        return max_mtg_cnt;
    }
};
// @lc code=end

