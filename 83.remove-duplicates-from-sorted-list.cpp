#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp;
        temp = head;
        while (temp != NULL && temp->next != NULL) {
            if(temp->val != temp->next->val) {
                temp = temp->next;
                continue;
            }
            while(temp != NULL && temp->next != NULL && temp->val==temp->next->val) {
                temp->next = temp->next->next;
                // temp = temp->next;
            }
            // if(temp->val==temp->next->val) temp->next = temp->next->next;
            // temp = temp->next;
            // if(temp==NULL) return head;
        }
        return head;
    }
};
// @lc code=end

