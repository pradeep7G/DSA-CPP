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
        vector<vector<vector<int>>> dp(size,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(0,m,n,strs,count,dp);
    }
};