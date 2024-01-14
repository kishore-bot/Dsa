// Medium
// https://leetcode.com/problems/determine-if-two-strings-are-close/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> word1_freq(26, 0), word2_freq(26, 0);
        vector<bool> word1_isPresent(26, false), word2_isPresent(26, false);

        for (char c : word1) {
            word1_freq[c - 'a']++;
            word1_isPresent[c - 'a'] = true;
        }

        for (char c : word2) {
            word2_freq[c - 'a']++;
            word2_isPresent[c - 'a'] = true;
        }

        sort(begin(word1_freq), end(word1_freq));
        sort(begin(word2_freq), end(word2_freq));

        return word1_freq == word2_freq && word1_isPresent == word2_isPresent;
    }
};