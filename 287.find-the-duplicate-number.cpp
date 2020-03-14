#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // find intersection
        int tortoise=nums[0];
        int hare=nums[0];
        do {
            tortoise=nums[tortoise];
            hare=nums[nums[hare]];
        } while (tortoise!=hare);
        // find the entrance of the cycle.
        int ptr1=nums[0];
        int ptr2=tortoise;
        while(ptr1!=ptr2){
            ptr1=nums[ptr1];
            ptr2=nums[ptr2];
        }
        return ptr1;
    }
};
// @lc code=end

