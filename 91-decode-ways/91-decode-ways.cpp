class Solution {
public:
    //recursion O(2^n) Tc, SC:O(n) RSS, memoized TC:O(n) SC:O(n)+O(n) rss
    int solve(int ind,string &s,int n,vector<int> &dp){
        if(ind==n)
            return 1;
        if(dp[ind]!=-1)
            return dp[ind];
        if(s[ind]=='0')
            return dp[ind]=0;
        int res=solve(ind+1,s,n,dp);
        if(ind+1 < n && (s[ind]=='1' || (s[ind]=='2'&& s[ind+1]<'7')))
            res+=solve(ind+2,s,n,dp);
        return dp[ind]=res;
    }
    // int bottomUp()
    int numDecodings(string s) {
       int n=s.length();
       vector<int> dp(n,-1);
       return solve(0,s,n,dp);
    }
};