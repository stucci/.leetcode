#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */

// @lc code=start
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int car_num = position.size();
        vector<pair<int, int>> pos_speed;
        for(int i=0; i<car_num; i++){
            pos_speed.push_back({target - position[i], speed[i]});
        }
        sort(pos_speed.begin(), pos_speed.end());

        int cnt=0;
        double max_arr_time=0;
        for(int i=0; i<car_num; i++){
            double arr_time = pos_speed[i].first * 1.0 / pos_speed[i].second;
            if(max_arr_time < arr_time){
                max_arr_time = arr_time;
                cnt++;
            }
        }
        return cnt;
    }
};
// @lc code=end

