// https://leetcode.com/problems/maximum-odd-binary-number/description/?envType=daily-question&envId=2024-03-01
// Easy
// String



#include <bits/stdc++.h>
using namespace std; 

#include <string>
using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans = "";
        int ones = 0;
        
        // Count the number of ones in the string
        for (auto ch : s) {
            if (ch == '1') {
                ans += '1';
                ones++;
            }
        }
        
        // If there are no ones, return the string
        if (ones == 0) return ans;
        else {
            string ch = "";
            
            // Append zeros to form the maximum odd binary number
            for (int i = ones; i < s.size(); i++) {
                ch += '0';
            }
            
            // Remove the last '1' from ans and append ch and '1'
            ans.pop_back();
            ans += ch;
            ans += '1';
        }
        return ans;
    }
};
