class Solution {
public:
    unordered_map<int,int> memo;
    int top_down(int n){
        if(memo.find(n)!=memo.end())
            return memo[n];
        if(n<=1)
            return memo[n]=1;
        int count=0;
        for(int i=1;i<=n;i++){
            int left=top_down(i-1);
            int right=top_down(n-i);
            count+=(left*right);
        }
        memo[n]=count;
        return count;
    }
    int bottom_up(int n){
        //dp[0] = 1, dp[1]=1, dp[2] =2 , dp[3]=dp[0]*dp[2] + dp[1]*d[1] + dp[2]*dp[0]; 2+1+2;
        vector<int> dp(n+1,0);
        dp[0]=1,dp[1]=1;
        for(int level=2;level<=n;level++){
            for(int root=1;root<=level;root++){
                dp[level]+=dp[level-root]*dp[root-1];
            }
        }
        return dp[n];
    }
    int numTrees(int n) {
        //catalan number nci * ncn-i;
        // BST brainstorm - key < root, search in the left tree, key > root search in the right tree
        
        // 1 2 3 4
        return top_down(n);
    }
};