// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    //code
    //sort and two pointers
    sort(arr,arr+size);
    int lo=0,hi=1;
    n=abs(n);
    while(lo<=hi && hi<size){
        int diff=abs(arr[lo]-arr[hi]);
        if(diff==n && lo!=hi)
         return true;
        if(diff > n){
            lo++;
        }
        else{
            hi++;
        }
    }
    return false;
}