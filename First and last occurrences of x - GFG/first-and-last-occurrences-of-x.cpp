// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // if(!binary_search(arr,arr+n,x)){
    //     return {-1,-1};
    // }
    // int p=lower_bound(arr,arr+n,x)-arr;
    // int q=upper_bound(arr,arr+n,x)-arr-1;
    // return {p,q};
    if(!binary_search(arr,arr+n,x))
    {
        return {-1,-1};
    }
    int lo=0,hi=n-1,ans=-1;
    vector<int> v;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(x==arr[mid]){
            ans=mid;
            hi=mid-1;
        }
        else if(x<arr[mid]){
            hi=mid-1;
        }
        else
            lo=mid+1;
    }
    v.push_back(ans);
    lo=0,hi=n-1,ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==x){
            ans=mid;
            lo=mid+1;
        }
        else if(x<arr[mid]){
            hi=mid-1;
        }
        else
            lo=mid+1;
    }
    v.push_back(ans);
    return v;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends