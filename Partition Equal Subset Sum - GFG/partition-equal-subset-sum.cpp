// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool solve(int n,int k,int arr[]){
        vector<vector<int>> dp(n+1,vector<int> (k+1));
        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }
        for(int j=1;j<=k;j++)
        {
            dp[0][j]=false;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                bool taken=false;
                if(j>=arr[i-1])
                    taken=dp[i-1][j-arr[i-1]];
                dp[i][j]= dp[i-1][j] || taken;
                }
        }
        return dp[n][k];
    }
    int equalPartition(int n, int arr[])
    {
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum&1)
            return 0;
        int target=sum/2;
        return solve(n,target,arr);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends