class Solution {
public:
    //memoize
    int solve(int i,int m,int n,vector<string> &strs,unordered_map<string,int> &count,vector<vector<vector<int>>> &dp){
        if(i==strs.size())
            return 0;
        //can include
        //cannot include
        if(dp[i][m][n]!=-1)
            return dp[i][m][n];
        int notTake=solve(i+1,m,n,strs,count,dp);
        //take
        int take=-1e6;
        int ones=count[strs[i]];
        int zeros=strs[i].length()-ones;
        if(ones<=n && zeros<=m){
            take=1+solve(i+1,m-zeros,n-ones,strs,count,dp);
        }
        return dp[i][m][n]=max(take,notTake);
    }
    int memo(vector<string>& strs, int m, int n) {
        int size=strs.size();
        unordered_map<string,int> count;
        for(int i=0;i<size;i++){
            int cnt=0;
            for(auto c:strs[i])
                if(c=='1')
                    cnt++;
            count[strs[i]]=cnt;
        }
        vector<vector<vector<int>>> dp(size,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(0,m,n,strs,count,dp);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size=strs.size();
        unordered_map<string,int> count;
        for(int i=0;i<size;i++){
            int cnt=0;
            for(auto c:strs[i])
                if(c=='1')
                    cnt++;
            count[strs[i]]=cnt;
        }
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        vector<vector<int>> cur(m+1,vector<int>(n+1,0));
        for(int i=size-1;i>=0;i--){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    int notTake=dp[j][k];
                    int take=-1e6;
                    int ones=count[strs[i]];
                    int zeros=strs[i].length()-ones;
                    if(k>=ones && j>=zeros){
                        take=1+dp[j-zeros][k-ones];
                    }
                    cur[j][k]=max(take,notTake);
                }
            }
            dp=cur;
        }
        return dp[m][n];
    }
};