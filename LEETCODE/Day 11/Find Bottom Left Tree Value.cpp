// yt =  https://www.youtube.com/watch?v=327Pn7rsJcs

// https://leetcode.com/problems/find-bottom-left-tree-value/
// MEDIUM

// TREE

/*
 * Idea using simple tree traversal + depth tracking or level tracking

Here so;ved using dfs
 * if root null then return
 *
 * kept a maxDepth gobal variable to ckech depth and ans variable
 *
 * if(depth > maxDepth){
 * maxDepth = depth
 * ans = root.val
 * }
 *
 * normal df traversal + depth +
 *
 * /
 *

*/


#include <bits/stdc++.h>
using namespace std; 
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxDepth;
    int leftMostValue;
    void helper(TreeNode *root, int depth)
    {
        if (root == NULL)
        {
            return;
        }
        if (maxDepth < depth)
        {
            maxDepth = depth;
            leftMostValue = root->val;
        }
        helper(root->left, depth + 1);
        helper(root->right, depth + 1);
    }
    int findBottomLeftValue(TreeNode *root)
    {
        leftMostValue = 0;
        maxDepth = -1;
        helper(root, 0);
        return leftMostValue;
    }
};