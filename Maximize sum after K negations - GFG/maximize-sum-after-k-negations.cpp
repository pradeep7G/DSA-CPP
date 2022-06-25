// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    typedef long long ll;
    long long int maximizeSum(long long int a[], int n, int k)
    {
       sort(a,a+n);
       int i=0;
       while(k){
           if(a[i]>=0)
               break;
           a[i] = -1 * a[i];
           i++;
           k--;
       }
       if(k){
           sort(a,a+n);
           a[0] = pow(-1,k)*a[0];
       }
       long long sum=0;
       for(int i=0;i<n;i++)
           sum+=a[i];
       
       return sum;
    }
};

// { Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}  // } Driver Code Ends