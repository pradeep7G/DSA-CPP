// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++
class Solution{
    public:
    int dp[1001][1001];
    bool solve(int i,int j,string wild,string pattern){
        if(i<0 && j<0)
         return true;
        if(i<0 || j<0) 
         return false;
        if(dp[i][j])
         return dp[i][j];
        if(wild[i]==pattern[j]){
           return dp[i][j]=solve(i-1,j-1,wild,pattern);
        }
        if(wild[i]=='?'){
           return dp[i][j]=solve(i-1,j-1,wild,pattern);
        }
        if(wild[i]=='*'){
            return dp[i][j]=solve(i,j-1,wild,pattern) || solve(i-1,j,wild,pattern) || solve(i-1,j-1,wild,pattern);
        }
        return dp[i][j]=false;
    }
    bool match(string wild, string pattern)
    {
        //dp memoization?
        int n=wild.size(),m=pattern.size();
        memset(dp,false,sizeof dp);
        return solve(n-1,m-1,wild,pattern);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}  // } Driver Code Ends