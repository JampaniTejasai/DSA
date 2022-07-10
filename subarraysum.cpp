// Algorithm:  

// 1.Create two variables, l=0, sum = 0
// 2.Traverse the array from start to end.
// 3.Update the variable sum by adding current element, sum = sum + array[i]
// 4.If the sum is greater than the given sum, update the variable sum as sum = sum – array[l], and update l as, l++.
// 5.If the sum is equal to given sum, print the subarray and break the loop.
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        int l=0;
        long long curr_sum=arr[0];
        vector<int> v;
        for(int i=1;i<=n;i++)
        {
            while(curr_sum > s && l<i-1)
            {
                curr_sum-=arr[l];
                l++;
            }
            if(sum == s)
            {
                v.push_back(l+1);
                v.push_back(i);
                return v;
            }
            if(i<n)
            {
                curr_sum+=arr[i];
            }
        }
        v.push_back(-1);
        return v;
    }
};


int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  