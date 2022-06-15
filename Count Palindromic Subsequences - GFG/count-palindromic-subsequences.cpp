// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int mod=1e9 + 7;
    long long int solve(int i,int j,string &str,vector<vector<long long>> &dp){
        if(i>j)
            return 0;
        if(i==j)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(str[i]==str[j]){
            return dp[i][j]=(1+solve(i,j-1,str,dp)+solve(i+1,j,str,dp))%mod;
        }
        return dp[i][j]=(mod + solve(i+1,j,str,dp) + solve(i,j-1,str,dp) - solve(i+1,j-1,str,dp))%mod;
    }
    long long int  countPS(string str)
    {
       vector<vector<long long>> dp(str.size(),vector<long long>(str.size(),-1));
       return solve(0,str.size()-1,str,dp);
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends