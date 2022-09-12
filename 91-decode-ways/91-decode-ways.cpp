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
        int res=0;
        res+=solve(ind+1,s,n,dp);
        if(ind+1 < n && (s[ind]=='1' || (s[ind]=='2'&& s[ind+1]<'7')))
            res+=solve(ind+2,s,n,dp);
        return dp[ind]=res;
    }
    int solvep1(int ind,string &s,int n,vector<int> &dp){
       if(ind==n)
           return 1;
        if(dp[ind]!=-1)
            return dp[ind];
        if(s[ind]=='0')
            return dp[ind]=0;
        int res=0;
        res+=solve(ind+1,s,n,dp);
        if(ind+1 < n and (s[ind]=='1' or (s[ind]=='2' and s[ind+1]<'7')))
            res+=solve(ind+2,s,n,dp);
        return dp[ind]=res;
    }
    int solvep2(string s){
        int n=s.length();
        vector<int> dp(n+1,0);
        dp[n]=1;
        for(int ind=n-1;ind>=0;ind--){
            if(s[ind]=='0')
                dp[ind]=0;
            else{
                dp[ind]=dp[ind+1];
                if(ind+1<n and (s[ind]=='1' or (s[ind]=='2' and s[ind+1]<'7')))
                    dp[ind]+=dp[ind+2];
            }
        }
        return dp[0];
    }
    int bottomUp(string s){
        int n=s.length();
        vector<int> dp(n+2,0);
        dp[n]=1;
        for(int ind=n-1;ind>=0;ind--){
            if(s[ind]=='0')
                dp[ind]=0;
            else{
                dp[ind]=dp[ind+1];
                if(ind+1<n && ((s[ind]=='1' || (s[ind]=='2'&& s[ind+1]<'7'))))
                    dp[ind]+=dp[ind+2];
            }
        }
        return dp[0];
    }
    int numDecodings(string s) {
        return solvep2(s);
       return bottomUp(s);
       int n=s.length();
       vector<int> dp(n,-1);
       return solve(0,s,n,dp);
    }
};