#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        ListNode* node=head;
        while(node!=NULL){
            v.push_back(node->val);
            node=node->next;
        }
        vector<int> w(rbegin(v),rend(v));
        return v==w;
    }
};
// @lc code=end

