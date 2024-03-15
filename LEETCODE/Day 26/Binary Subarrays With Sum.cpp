// Medium
// https://leetcode.com/problems/binary-subarrays-with-sum/description/?envType=daily-question&envId=2024-03-14

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int> mpp;
        int sum = 0;
        mpp[0] = 1; // Initialize with sum 0, as there's always one empty subarray with sum 0
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int x = sum - goal;
            if (mpp.find(x) != mpp.end()) {
                ans += mpp[x];
            }
            mpp[sum]++;
        }
        return ans;
    }
};
