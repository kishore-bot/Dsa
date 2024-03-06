// https://www.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1
// Medium
// String

#include <string>
using namespace std;

// Brutte
// Using two loop
class Solution
{
public:
    vector<int> search(string pattern, string text)
    {
        int n = text.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            string s = "";
            for (int j = i; j < n; j++)
            {
                s += text[j];
                if (s == pattern)
                {
                    ans.push_back(i + 1);
                }
            }
        }
        return ans;
    }
};


// Optimal  using rabin karrp algo


// https://www.youtube.com/watch?v=qQ8vS2btsxI
class Solution {
public:
    long long findHashCode(string s, int n) {
        long long hash = 0;
        for (int i = 0; i < n; i++) {
            hash = (hash * 26 + (s[i] - 'a' + 1)) % 1000000007; // Using a large prime as modulo
        }
        return hash;
    }

    vector<int> search(string pattern, string text) {
        int n = text.size();
        int m = pattern.size();
        vector<int> ans;
        long long hashVal = findHashCode(pattern, m);
        long long textVal = findHashCode(text.substr(0, m), m);
        if (textVal == hashVal) {
            string str = text.substr(0, m);
            if (str == pattern) ans.push_back(1);
        }
        long long power = 1;
        for (int i = 0; i < m - 1; i++) {
            power = (power * 26) % 1000000007; // Precomputing power of 26
        }
        for (int i = m; i < n; i++) {
            int val = text[i] - 'a' + 1;
            int firstVal = text[i - m] - 'a' + 1;
            textVal = (textVal - (firstVal * power) % 1000000007 + 1000000007) % 1000000007; // Rolling hash
            textVal = (textVal * 26 + val) % 1000000007;
            if (textVal == hashVal) {
                string str = text.substr(i - m + 1, m);
                if (str == pattern) ans.push_back(i - m + 2);
            }
        }
        return ans;
    }
};