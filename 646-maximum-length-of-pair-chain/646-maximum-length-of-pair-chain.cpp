class Solution {
public:
    int solve(int i,int n,vector<vector<int>>& pairs,vector<int> &dp){
        if(i==n)
            return 0;
        //notTake
        if(dp[i]!=-1)
            return dp[i];
        int notTake=solve(i+1,n,pairs,dp);
        vector<int> tmp={pairs[i][1],INT_MAX};
        int nextInd=upper_bound(begin(pairs),end(pairs),tmp)-begin(pairs);
        int take=1+solve(nextInd,n,pairs,dp);
        return dp[i]=max(notTake,take);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        //can select a pair or not??
        //return maxStringChain, so i explore allways
        //before that i sort pairs so that i can be able to select next interval which should be non-verlapping to the current interval
        int n=pairs.size();
        sort(begin(pairs),end(pairs));
        vector<int> dp(n,-1);
        return solve(0,n,pairs,dp);
    }
};