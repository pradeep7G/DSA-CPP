class Solution {
public:
    int uniquePaths(int m, int n) {
        //Time & space O(mXn) can could do it in O(1), the solutions is (n+m)! / (n!)(m!); careful with overflows
        // int dp[m][n];
        // for(int i=0;i<m;i++){
        //     dp[i][0]=1;
        // }
        // for(int i=0;i<n;i++){
        //     dp[0][i]=1;
        // }
        // for(int i=1;i<m;i++){
        //     for(int j=1;j<n;j++){
        //         dp[i][j]=dp[i-1][j]+dp[i][j-1];
        //     }
        // }
        // return dp[m-1][n-1];
        n--,m--;
        unsigned long long ans=1,j=1;
        for(int i=m+1;i<=m+n;i++,j++){
            ans*=i;
            ans/=j;
        }
        return ans;
    }
};