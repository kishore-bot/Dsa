// Easy
// String
// https://leetcode.com/problems/longest-common-prefix/
// NG

// Atcually solve using Trie
// Here we Solved Using sorting

/*
* sort the array
* assing v[0] to first and v[n-1] to last
*for loop:-> range from 0 -> min(first.size(),last.size())
    * if(first[i]!=last[i])
        * break;
    * ans+=first[i]

* return ans
*/

#include <bits/stdc++.h>
using name space struct 
{
public:
    string longestCommonPrefix(vector<string> &v)
    {
        string ans = "";
        sort(v.begin(), v.end());
        int n = v.size();
        string first = v[0], last = v[n - 1];
        for (int i = 0; i < min(first.size(), last.size()); i++)
        {
            if (first[i] != last[i])
            {
                return ans;
            }
            ans += first[i];
        }
        return ans;
    }
};