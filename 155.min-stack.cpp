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
        mi=INT_MAX;
    }
    
    void push(int x) {
        v.push_back(x);
        mi=*min_element(v.begin(), v.end());
    }
    
    void pop() {
        v.pop_back();
        // for(int i=1, mi=v[0];i<v.size();i++) mi=min(mi,v[i]);
        mi=INT_MAX;
        mi=*min_element(v.begin(), v.end());
    }
    
    int top() {
        return v[v.size()-1];
    }
    
    int getMin() {
        return mi;
    }
private:
    int mi;
    vector<int> v;
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

