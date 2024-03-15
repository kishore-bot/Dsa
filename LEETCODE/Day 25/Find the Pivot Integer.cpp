// EASY
// https://leetcode.com/problems/find-the-pivot-integer/?envType=daily-question&envId=2024-03-13

class Solution
{
public:
    int pivotInteger(int n)
    {
        if (n == 1)
            return 1;
        int sum = (n * (n + 1)) / 2;
        for (int i = 1; i <= n; i++)
        {
            int x = (i * (i + 1)) / 2;
            int y = (sum - x) + i;
            if (x == y)
                return i;
        }
        return -1;
    }
};