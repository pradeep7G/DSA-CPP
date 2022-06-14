// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
       sort(a,a+n);
       for(int i=0;i<n;i++){
           if(k<=0)
            break;
           if(a[i]<0){
               a[i]*=-1;
               k--;
           }
       }
       if(k>=1){
           if(k%2==1){
               sort(a,a+n);
               a[0]*=-1;
                 long long int sum=accumulate(a,a+n,0LL);
               return sum;
           }
           else{
               long long int sum=accumulate(a,a+n,0LL);
               return sum;
           }
       }
       else{
           long long int sum=accumulate(a,a+n,0LL);
           return sum;
       }
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