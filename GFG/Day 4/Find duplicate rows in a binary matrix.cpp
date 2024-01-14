// MEDIUM
// https://www.geeksforgeeks.org/problems/find-duplicate-rows-in-a-binary-matrix/1
// SET and Metrix

// We cam solve question using set

//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

class Solution
{   
public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        set<vector<int>> st;
        vector<int> ans;
        st.insert(matrix[0]);
        
        for (int i = 1; i < M; i++) {
            if (st.find(matrix[i]) != st.end()) {
                ans.push_back(i);
            } else {
                st.insert(matrix[i]);
            }
        }
        
        return ans;
    } 
};
