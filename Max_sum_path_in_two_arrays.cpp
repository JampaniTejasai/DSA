// Given two sorted arrays A and B of size M and N respectively. Each array may have some elements in common with the other array. Find the maximum sum of a path from the beginning of any array to the end of any of the two arrays. We can switch from one array to another array only at the common elements.Both the arrays are sorted.
// Note: Only one repeated value is considered in the valid path sum.
// Input:
// M = 5, N = 4
// A[] = {2,3,7,10,12}
// B[] = {1,5,7,8}
// Output: 35
// Explanation: The path will be 1+5+7+10+12 = 35.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method*/
     int max_path_sum(int A[], int B[], int l1, int l2)
    {
        int i=0,j=0,sum1=0,sum2=0,max_sum=0;
        while(i<l1 && j<l2)
        {
            if(A[i]<B[j]) sum1+=A[i++];
            else if(B[j]<A[i]) sum2+=B[j++];
            else
            {
                max_sum+=max(sum1,sum2);
                max_sum+=A[i++];
                j++;
                sum1=0;
                sum2=0;
            }
        }
        while(i<l1)
        {
            sum1+=A[i++];
        }
        while(j<l2) sum2+=B[j++];
        max_sum+=max(sum1,sum2);
        return max_sum;
        //Your code here
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int N,M;
        cin>>N>>M;
        fflush(stdin);
        int a[N],b[M];
        for(int i=0;i<N;i++)
            cin>>a[i];
        for(int i=0;i<M;i++)
            cin>>b[i];
        Solution obj;
        int result = obj.max_path_sum(a,b,N,M);
        cout<<result<<endl;
    }
}

  // } Driver Code Ends