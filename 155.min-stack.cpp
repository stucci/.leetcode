#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        int mi=(vp.empty()?x:min(x,vp.back().second));
        vp.push_back({x,mi});
    }

    void pop() {
        vp.pop_back();
    }

    int top() {
        return vp.back().first;
    }

    int getMin() {
        return vp.back().second;
    }
private:
    vector<pair<int,int>> vp;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

