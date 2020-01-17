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
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        int max_depth = 0;
        q.push(root);
        while(q.size()){
            max_depth++;
            for (size_t i = 0, n = q.size(); i < n; i++) {
                TreeNode* p = q.front();
                q.pop();
                if(p->left!=NULL) q.push(p->left);
                if(p->right!=NULL) q.push(p->right);
            }
        }
        return max_depth;
    }
};
// @lc code=end

