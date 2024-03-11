// EASY
// https://leetcode.com/problems/intersection-of-two-arrays/description/

#include <vector>
#include <unordered_set>

class Solution
{
public:
    std::vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::unordered_set<int> set1(nums1.begin(), nums1.end());
        std::unordered_set<int> intersect;

        for (int num : nums2)
        {
            if (set1.count(num))
            {
                intersect.insert(num);
            }
        }

        return std::vector<int>(intersect.begin(), intersect.end());
    }
};

// FROM LEETCODE MUCH MORE  REFINED
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> um;
        vector<int> res;
        for (int i = 0; i < nums1.size(); i++)
        {
            um[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            if (um.find(nums2[i]) != um.end())
            {
                res.push_back(nums2[i]);
                um.erase(nums2[i]);
            }
        }
        return res;
    }
};