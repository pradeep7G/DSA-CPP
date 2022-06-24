// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	
	public:
	typedef long long ll;
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    sort(arr,arr+n);
	    ll res=0;
	   for(int i=0;i<n-2;i++){
	       int start=i+1,end=n-1;
	       while(start<end){
	           ll su=arr[i]+arr[start]+arr[end];
	           if(su<sum){
	               res+=end-start;
	           }
	           if(su<sum){
	               start++;
	           }
	           else
	            end--;
	       }
	   }
	   return res;
	}
		 

};

// { Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends