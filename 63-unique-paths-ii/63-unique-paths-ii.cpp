class Solution {
public:
    //bruteforce==>memoized
    int solve(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &memo){
        //base cases
        if(i==0 && j==0 && grid[i][j]!=1)
            return 1;
        if(i<0 || j<0)
            return 0;
        if(memo[i][j]!=-1)
            return memo[i][j];
        if(grid[i][j]==1)
            return 0;
        int left=solve(grid,i,j-1,memo);
        int up=solve(grid,i-1,j,memo);
        return memo[i][j]=left+up;
    }
    int solvep1(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &grid){
        //base-cases:
        if(i==0 and j==0 and grid[i][j]!=1)
            return 1;
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(grid[i][j]==1)
            return dp[i][j]=0;
        int left=solvep1(i,j-1,dp,grid);
        int up=solvep1(i-1,j,dp,grid);
        return dp[i][j]=left+up;
    }
    int solvep2(vector<vector<int>> &grid){
        int m=grid.size(),n=grid[0].size();
        if(grid[0][0]==1)
            return 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    continue;
                if(j-1>=0)
                    dp[i][j]+=dp[i][j-1];
                if(i-1>=0)
                    dp[i][j]+=dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
    int solvep3(vector<vector<int>> &grid){
        int m=grid.size(),n=grid[0].size();
        if(grid[0][0]==1)
            return 0;
        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            vector<int> cur(n,0);
            for(int j=0;j<n;j++){
                if(i==0 and j==0){
                    cur[j]=1;
                    continue;
                }
                if(grid[i][j]==1)
                    continue;
                int up=0,left=0;
                if(i-1>=0)
                    up+=prev[j];
                if(j-1>=0)
                    left+=cur[j-1];
                cur[j]=up+left;
            }
            prev=cur;
        }
        return prev[n-1];
    }
    int bottomUp(vector<vector<int>>& grid){
        int m=grid.size(),n=grid[0].size();
        if(grid[0][0]==1)
            return 0;
        // vector<vector<int>> dp(m,vector<int>(n,0));
        // dp[0][0]=1;
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(grid[i][j]==1)
        //             continue;
        //         if(j-1>=0)
        //             dp[i][j]+=dp[i][j-1];
        //         if(i-1>=0)
        //             dp[i][j]+=dp[i-1][j];
        //     }
        // }
        // return dp[m-1][n-1];
        //space optimization
        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            vector<int> cur(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    cur[j]=1;
                    continue;
                }
                if(grid[i][j]==1)
                    continue;
               int up=0;
               int left=0;
               if(i>0)
                   up=prev[j];
               if(j-1>=0)
                   left=cur[j-1];
                cur[j]=up+left;
            }
            prev=cur;
        }
        return prev[n-1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        // return solvep2(grid);
        // return solvep3(grid);
        // return bottomUp(grid);
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solvep1(m-1,n-1,dp,grid);
    }
};