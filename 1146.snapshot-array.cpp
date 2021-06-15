#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1146 lang=cpp
 *
 * [1146] Snapshot Array
 */

// @lc code=start
class SnapshotArray {
public:
    unordered_map<int, map<int, int>> m; // {index : {snap_id_ : val}}
    int snap_id_ = 0;

    SnapshotArray(int length) {}

    void set(int index, int val) {
        m[index][snap_id_] = val;
    }

    int snap() {
        return snap_id_++;
    }

    int get(int index, int snap_id) {
        auto itr = m[index].upper_bound(snap_id);
        if(itr == m[index].begin()) return 0;
        return (*prev(itr)).second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
// @lc code=end

