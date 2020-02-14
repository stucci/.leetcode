#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int> um;
        while(head){
            if(um[head->next]) return true;
            um[head->next]++;
            head=head->next;
        }
        return false;
    }
};
// @lc code=end

