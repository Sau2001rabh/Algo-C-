/*Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
 
    long long maxSubarraySum(int arr[], int n){
        
        long long int cSum=0, maxSum=arr[0];
        for(long long int i=0; i<n; i++)
        {
            cSum+=arr[i];
            
            maxSum=(cSum>maxSum ? cSum : maxSum);
            if(cSum<0)
                cSum=0;
            
        }
        return maxSum;
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends

/*
Input: 
5
1 2 3 -2 5

Output: 
9
*/
