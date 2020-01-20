#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return NULL;
        if(nums.size()==1) return new TreeNode(nums[0]);
        int mid = nums.size() / 2;
        vector<int> lhs(nums.begin(), nums.begin() + mid);
        vector<int> rhs(nums.begin() + mid+1, nums.end());
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(lhs);
        root->right = sortedArrayToBST(rhs);
        return root;
    }
};
// @lc code=end

