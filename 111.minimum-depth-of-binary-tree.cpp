#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }else if(root->left == NULL && root->right != NULL || root->left != NULL && root->right == NULL){
            return max(minDepth(root->left)+1, minDepth(root->right)+1);
        }else{
            return min(minDepth(root->left)+1, minDepth(root->right)+1);
        }
    }
};
// @lc code=end

