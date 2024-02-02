// EASY
//https://leetcode.com/problems/climbing-stairs/?envType=daily-question&envId=2024-01-18
// DP

#include <bits/stdc++.h>
using namespace std;


// Brute
class Solution
{
public:
    int helper(int n)
    {
        if (n < 0)
            return 0;
        if (n == 0)
        {
            return 1;
        }

        return helper(n - 1) + helper(n - 2);
    }

    int climbStairs(int n)
    {
        if (n <= 0)
        {
            return 0;
        }
        return helper(n);
    }
};

// USING Dp

class Solution {
public:

    int solve(int i, int n, vector<int>& dp) {
        if (i == n) return 1;
        if (i > n) return 0;

        if (dp[i] != -1) return dp[i];

        dp[i] = solve(i + 1, n, dp) + solve(i + 2, n, dp);

        return dp[i];
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return solve(0, n, dp);
    }
};