// Easy
// Treee
// https://leetcode.com/problems/diameter-of-binary-tree/description/

/*
idea

* Base : root is null return 00;

* Body:
    * find left side height ans store on leftDepth variable // height(depth) section
    * find right side height ans store on rightDepth variable // height(depth) section
    * diameter = max(diameter, leftDepth + rightDepth); // diameter section
    *  return max(leftDepth, rightDepth) + 1 // height(depth) section
*/

#include <bits/stdc++.h>
using name space struct TreeNode struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        calculateDiameter(root, diameter);
        return diameter;
    }

    int calculateDiameter(TreeNode *root, int &diameter)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int leftDepth = calculateDiameter(root->left, diameter);
        int rightDepth = calculateDiameter(root->right, diameter);

        diameter = max(diameter, leftDepth + rightDepth);

        return max(leftDepth, rightDepth) + 1;
    }
};
