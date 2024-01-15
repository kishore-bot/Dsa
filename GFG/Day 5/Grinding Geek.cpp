// Medium
// https://www.geeksforgeeks.org/problems/grinding-geek/1

// Dp

// We need to dep  maxiumum and we here used Pick or pic idea


#include<bits/stdc++.h>
using namespace std;




class Solution {
public:
    int helper(int index, int n, int amount, const vector<int>& cost, vector<vector<int>>& dp) {
        if (index == n) {
            return 0;
        }
        if (dp[index][amount] != -1) {
            return dp[index][amount];
        }
        if (amount < cost[index]) {
            return dp[index][amount] = helper(index + 1, n, amount, cost, dp);
        } else {
            int amountLeft = amount - cost[index];
            int refund90 = cost[index] * 0.9;
            int amountLeftWithDiscount = amountLeft + refund90;
            int pick = 1 + helper(index + 1, n, amountLeftWithDiscount, cost, dp);
            int notPick = helper(index + 1, n, amount, cost, dp);
            return dp[index][amount] = max(pick, notPick);
        }
    }

    int max_courses(int n, int total, const vector<int>& cost) {
        vector<vector<int>> dp(n + 1, vector<int>(total + 1, -1));
        return helper(0, n, total, cost, dp);
    }
};
