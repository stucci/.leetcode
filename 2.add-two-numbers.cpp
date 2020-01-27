#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL&&l2==NULL) return NULL;
        if(l1!=NULL&&l2==NULL) return l1;
        if(l1==NULL&&l2!=NULL) return l2;
        ListNode* ret=new ListNode((l1->val+l2->val)%10);
        if(l1->next==NULL&&l2->next==NULL){
            if((l1->val+l2->val)/10){
                l1->next=new ListNode(1);
                l2->next=new ListNode(0);
            }else{
                return ret;
            }
        }else if((l1->val+l2->val)/10){
            l1->next->val+=1;
        }
        ret->next=addTwoNumbers(l1->next,l2->next);
        return ret;
    }
};
// @lc code=end

