// Easy 
// Trees
// https://leetcode.com/problems/leaf-similar-trees/description/




#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



// Using Bfs tree traversal  (Me)
class Solution {
public:

    void printLeaf(TreeNode* root, vector<int> &ans){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(root->val);
            return;
        }
        printLeaf(root->left, ans);
        printLeaf(root->right, ans);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        printLeaf(root1, v1);
        printLeaf(root2, v2);

        return v1 == v2;
    }
};



// Using DFS
class Solution {
public:
    void dfs(TreeNode* x, vector<int> &a) {
        if(!x) return;
        if(!x->left && !x->right) a.push_back(x->val);
        dfs(x->left, a);
        dfs(x->right, a);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        dfs(root1, a);
        dfs(root2, b);
        return a == b;
    }
};




int main() {
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->right->left = new TreeNode(9);
    root1->right->right = new TreeNode(8);

    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(1);
    root2->left->left = new TreeNode(6);
    root2->left->right = new TreeNode(7);
    root2->right->left = new TreeNode(4);
    root2->right->right = new TreeNode(2);

    Solution solution;
    bool areSimilar = solution.leafSimilar(root1, root2);
    if(areSimilar)
        cout << "The leaf sequences of the two trees are similar.";
    else
        cout << "The leaf sequences of the two trees are not similar.";
    return 0;
}
