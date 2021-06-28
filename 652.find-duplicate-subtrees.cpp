#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
 */

// approach
// dfs -> store set

// QA
// int?
// number of node?
// in following case, what output should I return?
//   1
//  2 1
//   2 1

// edge cases
// [1]
// []

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
public:
    map<vector<int>, int> m; // {subtree, count}
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> sub;
        helper(root, sub);
        return sub;
    }
    vector<int> helper(TreeNode* root, vector<TreeNode*>& sub){
        if(root==NULL) return {INT_MIN};
        vector<int> res;
        res.push_back(root->val);
        vector<int> leftsub = helper(root->left, sub);
        res.insert(res.end(), leftsub.begin(), leftsub.end());
        vector<int> rightsub = helper(root->right, sub);
        res.insert(res.end(), rightsub.begin(), rightsub.end());
        m[res]++;
        if(m[res]==2) sub.push_back(root);
        return res;
    }
};
// @lc code=end

