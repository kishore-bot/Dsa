// Stack + String
// https://www.geeksforgeeks.org/problems/remove-k-digits/1
// Medium

/*
S = 1 4  9 8 1

we push lemts in string to stack untile the stack top() > the elemet in string
if(Stack top > i'th element in string we pop element untile this condition break and also check K>0 so K--)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string S, int K)
    {
        int n = S.length();
        if (K >= n)
            return "0";
        stack<int> st;
        for (char digit : S)
        {
            while (!st.empty() and K > 0 and st.top() > digit) // pop from stack if the condition break
            {
                st.pop();
                K--;
            }
            st.push(digit);
        }
        while (K > 0) //if k is still remains so we need to pop
        {
            st.pop();
            K--;
        }
        string ans = "";
        while (!st.empty())
        {
            ans += st.top(); //adding elements in stack to string
            st.pop();
        }
        reverse(ans.begin(), ans.end()); //the string get from stack in reverse order so we correct that
        int len = ans.size();
        int startIndex = len;
        for (int i = 0; i < len; i++)
        {
            if (ans[i] != '0')
            {
                startIndex = i;//if there is trailing zero we need to remove that zero eg: 0021 we need to remove 00
                break;
            }
        }
        ans = (startIndex == len) ? "0" : ans.substr(startIndex);
        return ans;
    }
};
// https://www.youtube.com/watch?v=DTCbgSK4ams