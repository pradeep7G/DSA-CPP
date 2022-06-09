// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  int dp[101][101];
  int solve(int i,int n,int j,int m,string s,string t){
      if(i==n && j==m)
        return 0;
      if(i==n) return m-j;
      if(j==m) return n-i;
      
      if(dp[i][j]!=-1) return dp[i][j];
       
       if(s[i]==t[j])
        return dp[i][j]=solve(i+1,n,j+1,m,s,t);
       return dp[i][j]=1+min(solve(i,n,j+1,m,s,t),min(solve(i+1,n,j,m,s,t),solve(i+1,n,j+1,m,s,t)));
  }
  int solveiter(int n,int m,string s,string t){
      int dp[n+1][m+1];
      for(int i=0;i<=n;i++)
      {
          dp[i][0]=i;
      }
      for(int i=0;i<=m;i++){
          dp[0][i]=i;
      }
      for(int i=1;i<=n;i++){
          for(int j=1;j<=m;j++){
              if(s[i-1]==t[j-1]){
                  dp[i][j]=dp[i-1][j-1];
              }
              else
              {
                  dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
              }
          }
      }
      return dp[n][m];
  }
    int editDistance(string s, string t) {
        memset(dp,-1,sizeof dp);
       return solveiter(s.length(),t.length(),s,t);
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends