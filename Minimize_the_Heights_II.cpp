// Given an array arr[] denoting heights of N towers and a positive integer K.

// For each tower, you must perform exactly one of the following operations exactly once.

// Increase the height of the tower by K.
// Decrease the height of the tower by K ( you can do this operation only if the height of the tower is greater than or equal to K)
// Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

// You can find a slight modification of the problem here.
// Note: It is compulsory to increase or decrease the height by K for each tower.


// Example 1:

// Input:
// K = 2, N = 4
// Arr[] = {1, 5, 8, 10}
// Output:
// 5
// Explanation:
// The array can be modified as 
// {3, 3, 6, 8}. The difference between 
// the largest and the smallest is 8-3 = 5.

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        int ans = arr[n-1] - arr[0] ;
        int small = arr[0]+k;
        int large = arr[n-1]-k;
        int mi,ma;
        for(int i=0;i<n-1;i++)
        {
            mi = min(small,arr[i+1]-k);
            ma = max(large,arr[i]+k);
            if(mi<0) continue;
            ans = min(ans,ma-mi);
        }
        return ans;
        // code here
    }
};