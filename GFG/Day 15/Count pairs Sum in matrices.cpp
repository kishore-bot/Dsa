// Easy
// I not got anser
// https://www.geeksforgeeks.org/problems/count-pairs-sum-in-matrices4332/1

class Solution
{
public:
    bool find(vector<vector<int>> &mat2, int x)
    {
        int n = mat2.size();
        int start = 0;
        int end = n - 1;
        while (start < n && end >= 0)
        {
            if (x == mat2[start][end])
            {
                return true;
            }x
            if (x > mat2[start][end])
            {
                start++;
            }
            else
            {
                end--;
            }
        }
        return false;
    }

    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (find(mat2, x - mat1[i][j]))
                {
                    count++;
                }
            }
        }
        return count;
    }
};
