#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL) return 0;
        return pathSumFromRoot(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    int pathSumFromRoot(TreeNode* root, int sum){
        if(root==NULL) return 0;
        return (root->val==sum) + pathSumFromRoot(root->left, sum-root->val) + pathSumFromRoot(root->right, sum-root->val);
    }
};
// @lc code=end

