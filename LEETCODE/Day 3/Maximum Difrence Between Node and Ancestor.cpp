// Medium
// Tree
// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/


// Using Dfs and two variables maxValue and minValue


#include <bits/stdc++.h>
using namespace std;

// Tree Structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDiff(TreeNode* root, int maxValue ,int minValue){
        if(root == NULL) return maxValue - minValue;
        maxValue = max( maxValue , root->val);
        minValue = min(minValue,root->val);
        int left = maxDiff(root->left,maxValue,minValue);
        int right = maxDiff(root->right,maxValue,minValue);
        return max(left,right);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root == nullptr) return 0;
        return maxDiff(root ,root ->val,root->val);
    }
};