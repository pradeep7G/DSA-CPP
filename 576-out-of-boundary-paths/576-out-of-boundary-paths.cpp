class Solution {
public:
    typedef long long ll;
    typedef pair<ll,ll> doublet;
    long long ans=0;
    ll mod=1e9+7;
    // int dp[51][51][51];
    int dirs[5]={1,0,-1,0,1};
    ll bottomUp(int m,int n,int maxMove,int i,int j){
        //Test Case: m=1,n=2,maxMove=3,i=0,j=0 TRY!!
        vector<vector<int>> count(m,vector<int>(n,0));
        count[i][j]=1;
        ll ans=0;
        for(int step=0;step<maxMove;step++){
            vector<vector<int>> temp(m,vector<int>(n));
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    for(int dir=0;dir<4;dir++){
                        int x=i+dirs[dir],y=j+dirs[dir+1];
                        if(x<0||y<0||x>=m||y>=n)
                        {
                            ans=(ans+count[i][j])%mod;
                        }
                        else{
                            temp[x][y]=(temp[x][y]+count[i][j])%mod;
                        }
                    }
                }
            }
            count=temp;
        }
        return ans;
    }
    int topDownPractice(int m,int n,int maxMoves,int moves,int i,int j,vector<vector<vector<int>>> &dp){
        //base case: if out of boundary, that's true
        if(i<0 || j<0 || i>=m || j>=n)
            return 1;
        if(moves==maxMoves)
            return 0;
        if(dp[moves][i][j]!=-1)
            return dp[moves][i][j]%mod;
        ll temp=0;
        temp+=solve(m,n,maxMoves,moves+1,i-1,j,dp);
        temp+=solve(m,n,maxMoves,moves+1,i+1,j,dp);
        temp+=solve(m,n,maxMoves,moves+1,i,j-1,dp);
        temp+=solve(m,n,maxMoves,moves+1,i,j+1,dp);
        return dp[moves][i][j]=temp%mod;
    }
    ll solve(int m,int n,int maxMove,int moves,int i,int j,vector<vector<vector<int>>> &dp){
        if(i<0 || j<0 || i>=m || j>=n)
            return 1;
        if(moves==maxMove)
            return 0;
        if(dp[moves][i][j]!=-1)
            return dp[moves][i][j]%mod;
        ll temp=0;
        temp+=solve(m,n,maxMove,moves+1,i-1,j,dp);
        temp+=solve(m,n,maxMove,moves+1,i+1,j,dp);
        temp+=solve(m,n,maxMove,moves+1,i,j-1,dp);
        temp+=solve(m,n,maxMove,moves+1,i,j+1,dp);
        return dp[moves][i][j]=(temp)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        //maxMoves 2 1,1, 1,2,2,1
        //no.of paths possible
        //if we try recursive solution, there can be so many overlapping sub problem
        // return bottomUp(m,n,maxMove,startRow,startColumn);
        vector<vector<vector<int>>> dp(maxMove,vector<vector<int>>(m,vector<int>(n,-1)));
        return topDownPractice(m,n,maxMove,0,startRow,startColumn,dp);
    }
};