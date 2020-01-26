#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* cur=head;
        ListNode* ne=head->next;
        ListNode* pr=NULL;
        while(cur!=NULL){
            cur->next=pr;
            pr=cur;
            cur=ne;
            if(ne!=NULL) ne=cur->next;
        }
        return pr;
    }
};
// @lc code=end

