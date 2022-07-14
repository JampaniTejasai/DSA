
// Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.
 

// Example 1:

// Input:
// N = 3 
// A[] = {1,2,3} 
// Output:
// -1
// Explanation:
// Since, each element in 
// {1,2,3} appears only once so there 
// is no majority element.

int majorityElement(int a[], int size)
{
    int ansindex = 0;
    int count = 1;
    for(int i=1;i<size;i++)
    {
        if(a[i]==a[ansindex])
        {
            count++;
        }
        else count--;
        if(count == 0)
        {
            ansindex = i;
            count =1;
        }
    }
    if(count<1) return -1;
    else
    {
        int ans = a[ansindex];
        count=0;
        for(int i=0;i<size;i++)
        {
            if(a[i]==ans) count++;
        }
        if(count>(size)/2) return ans;
        else return -1;
    }
    // your code here
        
}