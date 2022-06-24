// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
       int lo=min(arr1[0],arr2[0]);
       int hi=max(arr1[n-1],arr2[m-1]);
       while(lo<=hi){
           int mid=lo+(hi-lo)/2;
           int x=upper_bound(arr1,arr1+n,mid)-arr1;
           int y=upper_bound(arr2,arr2+m,mid)-arr2;
           if(x+y < k){
               lo=mid+1;
           }
           else
                hi=mid-1;
       }
       return lo;
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends