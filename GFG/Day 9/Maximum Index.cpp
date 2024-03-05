// https://www.geeksforgeeks.org/problems/maximum-index-1587115620/1
// Med
// Array

// https://www.youtube.com/watch?v=e5_T1EIHNm0

#include <string>
using namespace std;
class Solution {
public:
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) {
        int ans = INT_MIN;
        int leftArray[n], rightArray[n];
        leftArray[0] = a[0];
        rightArray[n - 1] = a[n - 1];
        
        for (int i = 1; i < n; i++) {
            leftArray[i] = min(a[i], leftArray[i - 1]);
        }
        
        for (int i = n - 2; i >= 0; i--) {
            rightArray[i] = max(a[i], rightArray[i + 1]);
        }
        
        int i = 0, j = 0;
        while (j < n && i < n) {
            if (leftArray[i] <= rightArray[j]) {
                ans = max(ans, j - i);
                j++;
            } else {
                i++;
            }
        }
        return ans;
    }
};