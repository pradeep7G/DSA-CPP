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
    int editDistance(string s, string t) {
        memset(dp,-1,sizeof dp);
       return solve(0,s.length(),0,t.length(),s,t);
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