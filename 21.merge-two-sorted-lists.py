#
# @lc app=leetcode id=21 lang=python3
#
# [21] Merge Two Sorted Lists
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        head=ListNode(0)
        if l1==None and l2==None:
            return None
        elif l1==None:
            return l2
        elif l2==None:
            return l1
        elif l1.val<l2.val:
            head=l1
            l1.next=self.mergeTwoLists(l1.next, l2)
        else:
            head=l2
            l2.next=self.mergeTwoLists(l1, l2.next)
        return head
# @lc code=end

