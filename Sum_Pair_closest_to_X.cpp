// Given a sorted array arr[] of size N and a number X, find a pair in array whose sum is closest to X.

// Example 1:

// Input:
// N = 6, X = 54
// arr[] = {10, 22, 28, 29, 30, 40}
// Output: 22 30
// Explanation: As 22 + 30 = 52 is closest to 54.

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    vector<int> sumClosest(vector<int>arr, int x)
    {
        // code here
        int l=0,r=arr.size()-1,diff=INT_MAX;
        int first,second;
        while(l<r)
        {
            if(diff>abs(x-arr[l]-arr[r]))//If current sum arr[l],arr[r] is more closer to x then we change first and second values
            {
                diff = abs(x - arr[l] - arr[r]);
                first = arr[l];
                second = arr[r];
            }
            if(arr[l] + arr[r] < x)//If current sum arr[l],arr[j] is smaller than x then we required a larger value than arr[l] so we increment l
            {
                l++;
            }
            else r--;//If current sum arr[l],arr[j] is greater than x then we required a smaller value than arr[r] so we deccrement r
        }
        vector<int> v;
        v.push_back(first);
        v.push_back(second);
        return v;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumClosest(arr, x);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends