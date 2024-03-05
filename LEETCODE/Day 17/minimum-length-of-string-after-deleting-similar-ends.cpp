// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/?envType=daily-question&envId=2024-03-05
// Medium (for me easy)

#include <string>
using namespace std;


class Solution {
public:
    int minimumLength(string s) {
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right && s[left] == s[right]) {
            char ch = s[left];
            while (left <= right && s[left] == ch) {
                left++;
            }
            while (left <= right && s[right] == ch) {
                right--;
            }
        }
        
        return max(0, right - left + 1);
    }
};