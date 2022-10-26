class Solution {
public:
    //TC:O(n*2*3), At max n*2*3 states will be visited..
    //SC:O(n*2*3) + O(n) RSS
    int solve(int idx,int buy,int cap,vector<int> &prices,vector<vector<vector<int>>> &dp){
        if(cap==0 || idx >= prices.size())
            return 0;
        if(dp[idx][buy][cap]!=-1)
            return dp[idx][buy][cap];
        int profit;
        if(buy){
            //will buy or won't but
            profit=max(-prices[idx]+solve(idx+1,0,cap,prices,dp),solve(idx+1,1,cap,prices,dp));
        }
        else{
            //will sell or won't sell
            profit=max(prices[idx]+solve(idx+1,1,cap-1,prices,dp),solve(idx+1,0,cap,prices,dp));
        }
        return dp[idx][buy][cap]=profit;
    }
    int topDown(vector<int>& prices){
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,2,prices,dp);
    }
    int solve(vector<int> &prices){
        int n=prices.size();
        vector<int> pref(n);
        int minSoFar=prices[0];
        int ans=0;
        for(int i=0;i<n;i++){
            minSoFar=min(minSoFar,prices[i]);
            ans=max(ans,prices[i]-minSoFar);
            pref[i]=ans;
        }
        int maxSoFar=prices[n-1];
        ans=0;
          //WHY IS IT WORKING??
        //consider this case to illustrate what's happening if we do buy and sell at i,j and pref[j] store max profit upto that point,if jth element doesn't contribute to that profit then we know pref[i]+maxSoFar-prices[i] is valid and what if jth element involves in the second transaction then it will be pref[i]+maxSoFar-prices[i] ===> prices[i]-minSoFar+maxSoFar-prices[i] ==> maxSoFar-minSoFar which ith considered as only one BUY AND SELL TRANSACTION ,That's why it works, can't we do this to optimise space to O(1) let's see...
        for(int i=n-2;i>=0;i--){
            maxSoFar=max(maxSoFar,prices[i]);
            ans=max(ans,pref[i]+maxSoFar-prices[i]);
        }
        return ans;
    }
    int maxProfit(vector<int>& prices) {
       return solve(prices);
    }
};