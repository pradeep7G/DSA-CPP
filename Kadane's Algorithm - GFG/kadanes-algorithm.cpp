// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        long long sum=0,ans=INT_MIN;
        // bool ispos=false;
        // for(int i=0;i<n;i++)
        // {
        //     if(arr[i]>0)
        //     {
        //         ispos=true;
        //         break;
        //     }
        // }
        // int negans=arr[0];
        // for(int i=0;i<n;i++)
        // {
        //     negans=max(negans,arr[i]);
        // }
        // if(!ispos)
        //     return negans;
        // for(int i=0;i<n;i++)
        // {
        //     sum+=arr[i];
        //     if(ans<sum)
        //     {
        //         ans=sum;
        //     }
        //     if(sum<0)
        //      sum=0;
        // }
        for(int i=0;i<n;i++){
            sum+=arr[i];
            ans=max(ans,sum);
            if(sum<0)
            sum=0;
        }
        return ans;
        
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