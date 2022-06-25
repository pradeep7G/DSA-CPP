// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int MOD=1e9 + 7;
    long long int findMaxProduct(vector<int>&a, int n){
        //Write your code here  
        
        // if no zeros and even number of negs is it simply prod
        // else if no zeros and odd no.of negs then it is all prod except the one with maxnegvalue
        // if there are zeros is simply prod of evrything but zeros but following 1 and 2
        if(n==1)
         return a[0]%MOD;
        int count0=0,countneg=0,max_neg=INT_MIN;
        long long prod=1;
        for(int i=0;i<n;i++){
            if(a[i]==0)
             {
                 count0++;
                 continue;
             }
             if(a[i]<0){
                 max_neg=max(max_neg,a[i]);
                 countneg++;
             }
             prod=(prod*a[i])%MOD;
        }
        if(count0==n)
         return 0;
        if(countneg & 1){
            if(countneg==1 && count0>0 && countneg+count0==n)
             return 0;
             
             prod=prod/max_neg;
        }
        return prod%MOD;
    }
};



// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends