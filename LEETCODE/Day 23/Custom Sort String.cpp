// Medium
// https://leetcode.com/problems/custom-sort-string/
// String

// Solved using hash and two strings


// https://www.youtube.com/watch?v=8A3N6HWnWtI
class Solution
{
public:
    string customSortString(string order, string s)
    {
        int hash[26] = {0};
        string ans = "", res = "";
        for (auto a : order)
            hash[a - 'a']++;
        for (auto c : s)
        {
            if (hash[c - 'a'] == 0)
                res += c;
            else
                hash[c - 'a']++;
        }
        for (auto a : order)
        {
            while (hash[a - 'a'] > 1)
            {
                ans += a;
                hash[a - 'a']--;
            }
        }
        return ans + res;
    }
};