#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> node;
        queue<int> depth;
        int max_depth = 0;
        if(root==NULL) return max_depth;
        node.push(root);
        depth.push(1);
        while(node.size()){
            TreeNode* temp = node.front();
            // cout << temp->val << "\n";
            node.pop();
            // depth.push(depth.front()+1); depth.pop();
            // cout << "depth:" << depth.front() << "\n";
            max_depth = max(max_depth, depth.front());
            if(temp->left!=NULL){
                node.push(temp->left);
                depth.push(depth.front()+1);
            }
            if(temp->right!=NULL){
                node.push(temp->right);
                depth.push(depth.front()+1);
            }
            depth.pop();
        }
        return max_depth;
    }
};
// @lc code=end

