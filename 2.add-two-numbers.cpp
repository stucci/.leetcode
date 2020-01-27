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
        return addTwoNumbersWithCarry(l1, l2, 0);
    }
    ListNode* addTwoNumbersWithCarry(ListNode* l1, ListNode* l2, int c) {
        if(l1==NULL&&l2==NULL&&c==0) return NULL;
        if(l1==NULL&&l2==NULL&&c==1) return new ListNode(1);
        int sum=(l1?l1->val:0)+(l2?l2->val:0)+c;
        ListNode* ret=new ListNode(sum%10);
        ret->next=addTwoNumbersWithCarry((l1?l1->next:l1),(l2?l2->next:l2),sum/10);
        return ret;
    }
};
// @lc code=end

