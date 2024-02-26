
// Medium
// https://www.geeksforgeeks.org/problems/implement-atoi/1

#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Bruttee
class Solution
{
public:
    bool isSequential(int n)
    {
        int prevDigit = n % 10;
        n = n / 10;

        while (n > 0)
        {
            int currentDigit = n % 10;
            if (currentDigit + 1 != prevDigit)
            {
                return false;
            }
            prevDigit = currentDigit;
            n = n / 10;
        }

        return true;
    }

    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> ans;
        for (int i = low; i <= high; i++)
        {
            if (isSequential(i))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }

    // Otimal using recursin
    class Solution
    {
    public:
        void dfs(int low, int high, int i, int num, vector<int> &ans)
        {
            if (num >= low && num <= high)
            {
                ans.push_back(num);
            }
            if (num > high || i > 9)
            {
                return;
            }
            dfs(low, high, i + 1, num * 10 + i, ans);
        }

        vector<int> sequentialDigits(int low, int high)
        {
            vector<int> ans;
            for (int i = 1; i <= 9; i++)
            {
                dfs(low, high, i, 0, ans);
            }
            sort(ans.begin(), ans.end());
            return ans;
        }
    };
