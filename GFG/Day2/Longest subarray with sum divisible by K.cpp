
// Medium
// ARRAY HASH MAP
// https://www.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1

// Brutte Force Approch -> Using Nested Loop (N^2)
// Efficient -> using prefix sum (Hash map) and reminder

#include <bits/stdc++.h>
using namespace std;

// Brutte Force 

class Solution {
public:
    int longSubarrWthSumDivByK(int arr[], int n, int k) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j]; // Changed arr[i] to arr[j]
                if (sum % k == 0) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};

// Efficien O(n)tc and O(N) sc
class Solution {
public:    
    int longSubarrWthSumDivByK(int arr[], int n, int k) {
        int ans = 0;
        unordered_map<int, int> mpp;
        mpp[0] = -1; // {remainder, index}
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i]; // Sum at each step
            int rem = (sum % k + k) % k; // Finding remainder for each element added
            if (mpp.find(rem) == mpp.end()) { // If remainder not present in map, add it to map
                mpp[rem] = i;
            } else { // If remainder present
                ans = max(ans, i - mpp[rem]); // Find the length of subarray
            }
        }
        return ans;
    }
};
