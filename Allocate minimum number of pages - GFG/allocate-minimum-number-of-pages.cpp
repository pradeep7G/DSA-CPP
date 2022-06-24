// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    typedef long long ll;
    bool isvalid(int a[],long long n,long long m,long long mid){
        long long sum=0,count=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(sum>mid)
            {
                sum=a[i];
                count++;
            }
        }
        if(sum<mid)
        count++;
        if(count<=m)
        return true;
        return false;
    }
    int findPages(int a[], int n, int m) 
    {
       ll lo=-1,hi=-1;
       ll sum=0;
       for(int i=0;i<n;i++){
           sum+=a[i];
           lo=max(lo,(ll)a[i]);
           hi=max(hi,sum);
       }
       ll ans=-1;
       while(lo<=hi){
           ll mid=lo+(hi-lo)/2;
           if(isvalid(a,n,m,mid)){
               ans=mid;
               hi=mid-1;
           }
           else{
               lo=mid+1;
           }
       }
       if(ans==-1)
       return -1;
       return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends