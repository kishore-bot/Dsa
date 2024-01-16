// Medium

// https://www.geeksforgeeks.org/problems/sequence-of-sequence1155/1

// RECURISON

// idea of pick or not pick

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int help(int i, int j, int n, int m)
    {
        if (j == n)
            return 1; // j is index
        if (i > m)
            return 0; // i is value
        int pick = help(i * 2, j + 1, n, m);
        int notPick = help(i + 1, j, n, m);
        return pick + notPick;
    }
    int numberSequence(int m, int n)
    {
        return help(1, 0, n, m);
    }
};
