//You are given a set of non negaive integers partition those integers into two subsets such that absolute differnece of subset suma is mininmum.

#include<bits/stdc++.h>
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
    long long maxsum = 0;
    for(int i=0;i<n;i++) maxsum+=arr[i];
    vector<vector<bool>> dp(n,vector<bool>(maxsum+1,0));
    for(int i=0;i<n;i++) dp[i][0] = true;
    dp[0][arr[0]] = true;
    for(int ind=1;ind<n;ind++)
    {
        for(int target=1;target<=maxsum;target++)
        {
            bool not_take = dp[ind-1][target];
            bool take = false;
            if(target>=arr[ind]) take = dp[ind-1][target-arr[ind]];
            dp[ind][target] = take || not_take;
        }
    }
    long long int ans = INT_MAX;
    for(int i=0;i<=maxsum;i++)
    {
        if(dp[n-1][i]==1) ans = min(ans,abs(maxsum-2*i));
    }
    return ans;
}
