#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1110 lang=cpp
 *
 * [1110] Delete Nodes And Return Forest
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    // vector<TreeNode*> allnodes;
    vector<TreeNode*> forest;
    unordered_set<int> to_del;
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int val : to_delete) to_del.insert(val);
        delNodesHelper(root);
        if(root) forest.push_back(root);
        return forest;
    }
    void delNodesHelper(TreeNode* &root){
        if(root==NULL) return;
        delNodesHelper(root->left);
        delNodesHelper(root->right);
        if(to_del.count(root->val)){
            if(root->left != NULL) forest.push_back(root->left);
            if(root->right != NULL) forest.push_back(root->right);
            root = NULL;
            return;
        }
    };
};
// @lc code=end

