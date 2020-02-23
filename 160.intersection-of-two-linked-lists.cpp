#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tmpA=headA;
        unordered_map<ListNode*, bool> um;
        while(tmpA!=NULL){
            um[tmpA]=true;
            tmpA=tmpA->next;
        }
        ListNode* tmpB=headB;
        while(tmpB!=NULL){
            if(um[tmpB]==true) return tmpB;
            tmpB=tmpB->next;
        }
        return NULL;
    }
};
// @lc code=end

