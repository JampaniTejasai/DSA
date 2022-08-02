// You are given an array 'ARR' of 'N' positive integers. Your task is to find if we can partition the given array into two subsets such that the sum of elements in both subsets is equal.


// For example, let's say the given array is [2, 3, 3, 3, 4, 5], then the array can be partitioned as [2, 3, 5]. and [3, 3, 4] with equal sum 10.

bool func(int ind,long long int sum,vector<int> &arr, vector<vector<int>>&dp){
    if(ind == 0) return arr[0]==sum;
    if(dp[ind][sum]!=-1) return dp[ind][sum];
    bool not_take = func(ind-1,sum,arr,dp);
    bool take = false;
    if(sum>=arr[ind]) take = func(ind-1,sum-arr[ind],arr,dp);
    return dp[ind][sum] = take||not_take;
}

bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
    long long int maxsum=0;
    for(int i=0;i<n;i++) maxsum+=arr[i];
    if(maxsum%2==1) return false;
    vector<vector<int>> dp(n,vector<int>((maxsum/2)+1,-1));
    return func(n-1,maxsum/2,arr,dp);
}
