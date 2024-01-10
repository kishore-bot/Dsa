
// Medium
// Tree
// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/
//https://www.youtube.com/watch?v=1gNbNxbokxc

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


// O(N+N) Tc,Sc O(N)

// Optimal
// Convert to grap using dfd ->Convert function used for that
// On Graph do bfs and each level count minutes or increace minutes
class Solution {
public:
    void convert(TreeNode* root, int parent, std::unordered_map<int, std::vector<int>>& gr) {
        if (root == nullptr) return;
        vector<int>& adjacent = gr[root->val];
        if (parent != 0) adjacent.push_back(parent);
        if (root->left != nullptr) adjacent.push_back(root->left->val);
        if (root->right != nullptr) adjacent.push_back(root->right->val);

        convert(root->left, root->val, gr);
        convert(root->right, root->val, gr);
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, std::vector<int>> gr;
        convert(root, 0, gr); // Convert tree to graph
        queue<int> q;
        q.push(start);
        int minute = 0;
        unordered_set<int> visited;
        visited.insert(start);
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int node = q.front();
                q.pop();
                for (int child : gr[node]) {
                    if (visited.find(child) == visited.end()) {
                        visited.insert(child);
                        q.push(child);
                    }
                }
            }
            minute++;//when level done increase to 1
        }
        return minute - 1;
    }
};
