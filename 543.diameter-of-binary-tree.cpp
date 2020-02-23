#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        return max({diameterOfBinaryTreeFromRoot(root), diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)});
    }
    int diameterOfBinaryTreeFromRoot(TreeNode* root) {
        if(root==NULL) return 0;
        return getDepth(root->left) + getDepth(root->right);
    }
    int getDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return 1 + max(getDepth(root->left), getDepth(root->right));
    }
};
// @lc code=end

