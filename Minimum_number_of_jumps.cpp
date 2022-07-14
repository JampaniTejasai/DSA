//Given an array of N integers arr[] where each element represents the max number of steps that can be made forward from that element.
//Find the minimum number of jumps to reach the end of the array (starting from the first element).
//If an element is 0, then you cannot move through that element.

// Note: Return -1 if you can't reach the end of the array.


// Example 1:

// Input:
// N = 11 
// arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} 
// Output: 3 
// Explanation: 
// First jump from 1st element to 2nd 
// element with value 3. Now, from here 
// we jump to 5th element with value 9, 
// and from here we will jump to the last.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int pos = 0;//max position we can reach
        int jump = 0;//minimum jumps required
        int destination = 0;//to which index we can reach at each step that is a[i]+i
        for(int i=0;i<n-1;i++)
        {
            destination = max(destination, arr[i] + i);//update destination to max destination we can reach
            if(pos == i)//If we reach max destination index from previous jump increment jump and if we cannot reach to other index then return -1 otherwise update pos to max destination we can reach based on previous jump
            {
                jump++;
                if(destination <= i) return -1;
                pos = destination;
            }
        }
        return jump;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends