#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for (auto& e: nums) m[e]++;
        auto comp = [](auto a, auto b){ return a.second < b.second; };
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            decltype(comp)> pq(m.begin(), m.end(),comp);
        vector<int> v;
        for (long long i = 0; i < k; i++) {
            v.push_back(pq.top().first);
            pq.pop();
        }
        return v;
    }
    vector<int> topKFrequentInit(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for (long long i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        auto comp = [](pair<int,int> a, pair<int,int> b){
            return a.second < b.second;
        };
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            decltype(comp)> pq{comp};
        for (auto& e: m) {
            pq.push(e);
        }
        vector<int> v;
        for (long long i = 0; i < k; i++) {
            auto p=pq.top();
            v.push_back(p.first);
            pq.pop();
        }
        return v;
    }
};
// @lc code=end

