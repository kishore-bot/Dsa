
// Medium
// https://www.geeksforgeeks.org/problems/implement-atoi/1


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int atoi(string s) {
        int n = 0;
        int neg = 1;
        int start=0;
        if(s[0]=='-')
        {
            neg=-1;
            start=1;
        }
        for (int i = start; i < s.size(); i++) {
            int ch = s[i] - '0';
            if (ch > 9 || ch < 0) return -1;
            n = n * 10 + ch;
        }
        return n*neg;
    }
};