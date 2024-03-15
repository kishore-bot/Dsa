// Array
// Medium
// https://leetcode.com/problems/product-of-array-except-self/description/

// Solved using idea suufix and prefix

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        int suffix = 1;
        for (int i = n - 2; i >= 0; i--) {
            suffix *= nums[i + 1];
            ans[i] *= suffix;
        }
        return ans;
    }
};
// https://www.youtube.com/watch?v=1z6dJ2qgnas&t=1075s