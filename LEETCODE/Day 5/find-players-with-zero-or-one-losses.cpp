// Medium
// https://leetcode.com/problems/find-players-with-zero-or-one-losses/

// Idea using hash Map


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches) {
        std::unordered_map<int, int> win, loss;

        // Count wins and losses
        for (int i = 0; i < matches.size(); i++) {
            win[matches[i][0]]++;
            loss[matches[i][1]]++;
        }

        // Find players who have not lost any matches
        std::vector<int> resWin;
        for (const auto& player : win) {
            if (loss.find(player.first) == loss.end() && player.second >= 1) {
                resWin.push_back(player.first);
            }
        }

        // Find players who have lost exactly one match
        std::vector<int> resLoss;
        for (const auto& player : loss) {
            if (player.second == 1) {
                resLoss.push_back(player.first);
            }
        }

        // Sort the results
        std::sort(resWin.begin(), resWin.end());
        std::sort(resLoss.begin(), resLoss.end());

        return {resWin, resLoss};
    }
};
