// EASY
// https://leetcode.com/problems/unique-number-of-occurrences/description/

// USING HASHING


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        std::unordered_map<int, int> occurrences;

        for (int num : arr) {
            occurrences[num]++;
        }

        std::unordered_set<int> uniqueOccurrencesSet;
        for (const auto& entry : occurrences) {
            int frequency = entry.second;
            if (uniqueOccurrencesSet.find(frequency) != uniqueOccurrencesSet.end()) {
                return false;
            }
            uniqueOccurrencesSet.insert(frequency);
        }

        return true;
    }
};